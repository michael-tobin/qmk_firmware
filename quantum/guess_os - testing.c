#include "guess_os.h"

#include "eeprom.h"
#include "print.h"

uint16_t usb_setups[STORED_USB_SETUPS];

struct setups_data_t {
    uint8_t count;
    uint8_t cnt_202;
    uint8_t cnt_404;
    uint8_t cnt_ffff;
    uint16_t last_wlength;
};

struct setups_data_t setups_data = {
    .count = 0,
    .cnt_202 = 0,
    .cnt_404 = 0,
    .cnt_ffff = 0,
};

void process_wlength(const uint16_t w_length) {
    usb_setups[setups_data.count] = w_length;
    setups_data.count++;
    setups_data.last_wlength = w_length;
    if (w_length == 0x202) {
        setups_data.cnt_202++;
    } else if (w_length == 0x404) {
        setups_data.cnt_404++;
    } else if (w_length == 0xFFFF) {
        setups_data.cnt_ffff++;
    }
}

// Some data I collected:
// Windows 10: [FFFF, FFFF, 404, 2424, FFFF, 404, FFFF, 2424, FFFF, 404, 2424, 404, 2424, 404, 2424, A0A, A0A, A0A, A0A, A0A, A0A, A0A, A0A, A0A, A0A, A0A, A0A, A0A, A0A, A0A, A0A, 0, 0, A0A, A0A, A0A, A0A, A0A, A0A, A0A, A0A]
// Another host with Windows 10: [FFFF, FFFF, 404, 2424, 404, 2424, FFFF, FFFF, FFFF, 404, 2424, 404, 2424, 404, 2424, 0, 0]
// Another Windows 10 variant: [FFFF, FFFF, 404, 2424, 404, 2424, 404, 2424, 404, 2424, 404, 2424]
// macOS 12.5: [202, 2424, 202, 2828, FFFF]
// iOS/iPadOS 15.6: [202, 2424, 202, 2828]
// Linux (including Android, Raspberry Pi and WebOS TV): [FFFF, FFFF, FFFF]
// PS5: [202, 404, 202, 2828, 202, 2424]
// Nintendo Switch: [8282, FFFF, 4040, 4040, FFFF, 4040, 4040, FFFF, 4040, 4040, FFFF, 4040, 4040, FFFF, 4040, 4040]
// Quest 2: [FFFF, FFFF, FFFF, FEFE, FFFF, FEFE, FFFF, FEFE, FFFF, FEFE, FFFF]
OSVariant guess_host_os(void) {
    if (setups_data.count < 3) {
        return OS_UNSURE;
    }
    if (setups_data.cnt_404 > 1) {
        // Windows usually has five packets with 0x404.
        if (setups_data.count > 10 && setups_data.cnt_ffff > 1 && setups_data.cnt_404 > 3) {
            return OS_WINDOWS;
        } else {
            return OS_UNSURE;
        }
    }
    if (setups_data.count == setups_data.cnt_ffff) {
        // Linux has 3 packets with 0xFFFF.
        return OS_LINUX;
    }
    if (setups_data.count < 10 && setups_data.last_wlength == 0xFFFF && setups_data.cnt_ffff == 1 && setups_data.cnt_202 == 2) {
        // MacOS has 5 packets.
        return OS_MACOS;
    }
    if (setups_data.count < 10 && setups_data.last_wlength == 0x2828 && setups_data.cnt_ffff == 0 && setups_data.cnt_202 == 2) {
        // iOS and iPadOS don't have the last 0xFFFF packet.
        return OS_IOS;
    }
    if (setups_data.cnt_ffff == 0 && setups_data.cnt_202 == 3) {
        // This is actually PS5.
        return OS_LINUX;
    }
    if (setups_data.cnt_ffff > 3 && setups_data.cnt_202 == 0 && setups_data.cnt_404 == 0) {
        // This is actually Quest 2 or Nintendo Switch.
        return OS_LINUX;
    }
    //return OS_UNSURE;
    return OS_MACOS;

}


void print_all_setups(void) {
#ifdef CONSOLE_ENABLE
  uint8_t cnt = eeprom_read_byte(EEPROM_USER_OFFSET);
  for (int i = 0; i < cnt; ++i) {
    uprintf("i: %d, wLength: %X\n", i, eeprom_read_word((uint16_t *)(EEPROM_USER_OFFSET + i * 2 + 1)));
  }
#endif
}

void store_setups_in_eeprom(void) {
  eeprom_update_byte(EEPROM_USER_OFFSET, setups_data.count);
  for (int i = 0; i < setups_data.count; ++i) {
    eeprom_update_word((uint16_t *)(EEPROM_USER_OFFSET + i * 2 + 1), usb_setups[i]);
  }
}