# abgx360gui-rs

This is an experimental rewrite of the original wxWidgets based `abgx360gui` using Rust and the [Slint](https://slint.dev/) UI toolkit. The goal is to provide a lightweight cross‑platform interface that retains the feel of the classic GUI.

## Building

```bash
cd abgx360gui/abgx360gui-rs
cargo build
```

## Running

```bash
cargo run
```

The compiled application lets you choose an input file and run `abgx360` with it. The UI is intentionally minimal but demonstrates how the original program could be ported to Slint.

