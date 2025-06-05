# note

## What is this?
A minimal and fast command-line scratchpad for quick note-taking, written in C.

## Features
- Add notes
- List notes
- Delete notes
- Edit notes
- Plaintext storage at `~/.local/share/note/notes.txt`
- No external packages to install, cJSON is included and built automatically

## Usage

```bash
note add "Call John"
note list
note delete 1
```

## Build

```bash
make      # Builds the default release version
make debug  # Builds with -g debug flags
```

## Install

```bash
make
sudo make install
```
This will copy the compiled binary to `/usr/local/bin/note`, making it accessible from anywhere in your terminal.

## Roadmap
- [x] Add notes
- [x] List notes
- [x] Delete notes
- [x] Clear all notes
- [x] Edit a note
- [ ] Search notes
- [x] Timestamps

## Nice to Have
- Optional encryption
- Config file support
- TUI (terminal UI) using ncurses
- Note tagging
- Import/export

## License

[MIT](https://github.com/nicolast654/note/blob/main/LICENSE)

## Third-Party Libraries

This project includes the [cJSON](https://github.com/DaveGamble/cJSON) library by Dave Gamble, a lightweight JSON parser in C, distributed under the MIT License.

The source code is located in `third_party/cJSON/`, and the original license has been preserved in `third_party/cJSON/LICENSE`.
