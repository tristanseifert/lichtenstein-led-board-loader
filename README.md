# Lichtenstein LED Board Bootloader
A basic bootloader that can upgrade the STM32F0's internal flash by reading an image out of an external SPI flash.

The loader also keeps track of which firmwares failed (reset often) and can automatically restore to the previous version (or a failsafe version).
