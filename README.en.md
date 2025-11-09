# Taskbar Margin

## Visual Effect
Transforms your taskbar into a static style similar to RoundedTB
The taskbar won't pop up when the mouse reaches the bottom edge of the screen
![效果图](./imgs/QQ20251109-172755.png)

## Problem Solved
If you're like me and prefer maximum screen real estate by enabling auto-hide taskbar, but don't want accidental mouse movements to trigger the taskbar when using maximized applications - especially when it makes clicking certain function buttons difficult.
![例子](./imgs/QQ20251109-173705.png)

## How It Works
1. Locates the taskbar window
2. Reassigns its `HRGN` (window region)

## Enable
- Double-click to run directly
- Or use PowerShell:
    ```powershell
    .\tb.exe
    ```
- Auto-start on boot:
Type `shell:startup` in File Explorer to navigate to the startup folder, then place a shortcut to the program there.

## Restore
- Restart File Explorer
- Use PowerShell:
    ```shell
    .\tb.exe -r
    ```

## Limitations
- No multi-monitor support
- May stop working after some time
- Requires pressing the Windows key to bring up the taskbar
- Noticeable jagged edges with large corner radii