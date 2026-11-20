# The Screens

A Raspberry Pi-based project for driving RGB LED matrices with custom silly visuals & almost storytelling. It sequence text and animations to tell (or not to tell) a narrative. It's like a digital LED comic book.

<img width="2896" height="1577" alt="IZPbEZ-O" src="https://github.com/user-attachments/assets/29a01de2-93d6-4cd9-9b2d-976ba1c52b4b" />

## Part 1: Development

This project depends on the [hzeller/rpi-rgb-led-matrix](https://github.com/hzeller/rpi-rgb-led-matrix) library. Both folders **must** reside in the same parent directory.

```bash
# Clone the library
git clone [https://github.com/hzeller/rpi-rgb-led-matrix.git](https://github.com/hzeller/rpi-rgb-led-matrix.git)

# Clone this project
git clone [https://github.com/your-username/smth-about-hypnosis.git](https://github.com/your-username/smth-about-hypnosis.git)

```
```
project/
├── rpi-rgb-led-matrix/
├── smth-about-hypnosis/
    └── README.md
```

### Connect to your Raspberry Pi via SSH
```bash
ssh raspberry@raspberrypi.local
```

To rsync your local code with the Pi, refer to the `scripts/readme.md` 


### Build and Run
This will also build `rpi-rgb-led-matrix` library

```bash
make pro && sudo ./pro
```

## Part 2: Showcase 

### Auto start setup
Run the installation script to set up the project as a systemd service:

```bash
cd scripts
chmod +x install.sh
./install.sh
```

### Check service logs

```bash
journalctl -u smth-about-hypnosis -f
```

### Start service

```bash
#!/bin/bash
set -euo pipefail
sudo systemctl start smth-about-hypnosis
sudo systemctl status smth-about-hypnosis --no-pager || true
```

### Stop service

```bash
#!/bin/bash
set -euo pipefail
sudo systemctl stop smth-about-hypnosis
sudo systemctl status smth-about-hypnosis --no-pager || true
```

### Disable service

```bash
#!/bin/bash
set -euo pipefail
sudo systemctl stop smth-about-hypnosis
sudo systemctl disable smth-about-hypnosis
```
