# Runtime Cardputer / ADV / Cardenza support

Build `pio run -e m5cardputer`; `cardenza` is a compatibility alias for the same hardware detection.

The normal default build uses [203Null/M5Unified](https://github.com/203Null/M5Unified/tree/74fe31c6d9a2bd7c04f81eb4f8f0af99262e3bc2) at immutable commit `74fe31c6d9a2bd7c04f81eb4f8f0af99262e3bc2`, M5GFX 0.2.31 and M5Cardputer 1.1.1. One app image selects original Cardputer, Cardputer ADV or Cardenza at runtime. ES8156 identification, codec initialization, GPIO21 LED hold, and Cardenza-only suppression of battery ADC/charging, RGB and IMU are owned by M5Unified. No `CARDENZA_TARGET`, forced board identity, or Power/LED linker wrappers are used by these builds. Original/ADV initialization remains the library's normal path.

Install only the app BIN through Launcher; preserve its bootloader and partition table. The new unified images have been compiled and audited on the host; they have not been flashed or physically tested. Earlier device logs under `../artifacts/` apply only to the older forced Cardenza images.

The app additionally guards its direct NeoPixel writes, battery UI/rewards/mood and charging mode with `M5.isCardenza()`. The charging item and shortcut remain available on original/ADV. Cardenza cannot detect external power: its SD-format confirmation explicitly asks the user to connect power and retains the destructive confirmation. Its GPS UART/CapLoRa startup is unavailable because the configured connector pins belong to the codec/keyboard; no alternate wiring is invented. SD, display, matrix keyboard and M5 Speaker features are retained. All three boards have no PSRAM, so this family build undefines BOARD_HAS_PSRAM.

`baseline-radio-disabled` and `cardenza-radio-disabled` remain explicitly guarded startup-only variants: IDLE and no WiFi start, promiscuous capture or raw TX. The normal artifact preserves application behavior, including automatic background reconnaissance; it must not be substituted for the guarded startup test. No security/radio feature was exercised during this migration. The previous stock and Cardenza build artifacts remain unchanged.

Old `src/cardenza_hal.h` and `src/cardenza_m5_power.cpp` are retained as historical port sources; they are not active in these targets. The latter compiles no wrappers without the removed force-target macro. Private build core: C:/pio-utility.

## Launcher publication protection

The published `cardenza` compatibility target adds `LAUNCHER_NVS_GUARD` and wraps only esp_partition_erase_range to refuse a whole shared NVS erase. This install-context guard is independent of runtime hardware detection and is retained in the guarded test aliases. Normal NVS page garbage collection and app/filesystem erases still pass through. Run `python support/test_nvs_guard.py`. Build/publication CI retains the cardenza alias and its existing app/license asset paths. See docs/LAUNCHER_PUBLISHING.md.
