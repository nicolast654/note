# note

## What is this?
A minimal and fast command-line scratchpad for quick note-taking, written in C.

## Features
- Add, list, and delete notes from your terminal
- Notes saved to `~/.local/share/note/notes.txt`
- Built from scratch with no dependencies

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
- [ ] Edit a note
- [ ] Search notes
- [ ] JSON backend
- [ ] Timestamps

## Nice to Have
- Optional encryption
- Config file support
- TUI (terminal UI) using ncurses
- Note tagging
- Import/export

## License

[MIT](https://github.com/nicolast654/note/blob/main/LICENSE)
