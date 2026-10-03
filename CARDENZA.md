# Cardenza support

This target retains the original Cardputer display and matrix-keyboard layout.
It verifies the ES8156 codec on SDA2/SCL1 and uses stereo Philips I2S,
16-bit samples and 32 BCLK per frame on BCLK41/LRCK43/DOUT42.
GPIO21 is held high to disable the keyboard LED. Cardenza has no battery,
charging detector, IMU or PSRAM; unavailable hardware is not simulated.
The original application license and third-party notices remain in force.

Build the normal application with `pio run -e cardenza`. Install only
`.pio/build/cardenza/firmware.bin` through Software Launcher. Preserve the
existing bootloader, partition table, otadata and shared NVS.
The target refuses whole shared-NVS erasure during Arduino recovery while
allowing normal NVS page garbage collection and unrelated partition writes.
Run `python3 support/test_nvs_guard.py` to verify this forwarding contract.
Successful compilation does not prove physical display, keys, audio or RF.
No wireless/security functionality is executed by these build checks.

M5Unified is pinned to separately compiled 0.2.22. Power/RGB initialization,
nonexistent battery/charge UI and charging rewards are excluded for Cardenza.
The SD format dialog retains its destructive-operation confirmation and asks
the user to connect power rather than querying an absent charging detector.
`cardenza-radio-disabled` is a separate guarded startup-test variant.
The HAL license is `scripts/CARDENZA-HAL-LICENSE`.
