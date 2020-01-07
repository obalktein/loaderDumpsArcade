# Loader Dumps Arcade (wip)

#### All this is a homebrew development with reverse engineering, non official technical documentation and a lot of personal time. 
Twitter : https://twitter.com/vicboma1

## Table of Contents (wip)

### [Systems](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#systems-1)
### [Loader](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#loader--based-on-injections)

### Injections
#### [Process](https://github.com/vicboma1/Inject-DLL/blob/master/README.md#process)
  * CreateProcess and OpenProcess
  * CreateRemoteThread and LoadLibrary
  * Portable Execute
  * Hook Injection
#### Techniques
  * Virtual Method Table 
  * Vectored Exception Handling
  * Trampoline/Columpio
  * DetourFunction
#### [Hooks](https://github.com/vicboma1/Inject-DLL/blob/master/README.md#hooks)
  * [Api Windows](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/readme.md#windows)
  * [Api Native NTxxx](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/readme.md#api-native-nt)
  * [Api Native ZWxxx](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/readme.md#api-native-zw)
  * [D3D8](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/D3D8/D3D8Hook.h)
  * [D3D8Device](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/D3D8/D3D8DeviceHook.h)
  * [DSound8](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/DSound8/DSound8Hook.h)
  * [DSoundBuffer](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/DSoundBuffer/DSoundBufferHook.h)
  * [D3D9](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/D3D9/D3D9Hook.h)
  * D3D9ex
  * [D3D9Device](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/D3D9/D3D9DeviceHook.h)
  * [Opengl32](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/readme.md#opengl)
  * [Glu32](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Platform/Hooks/readme.md#glu)
  
 #### [Segmentation memory](https://github.com/vicboma1/Inject-DLL/blob/master/README.md#segmentation-memory)
  * Addressing

### [Inputs](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#inputs-1)
### [JVS I/O Emulation](https://github.com/vicboma1/loaderDumpsArcade#jvs-io-emulation-1)
### [Graphics](https://github.com/vicboma1/loaderDumpsArcade#graphics-1)
### [Sound](https://github.com/vicboma1/loaderDumpsArcade#sound-1)
### [Virtual Storage](https://github.com/vicboma1/loaderDumpsArcade#virtual-storage-1)
### [Cache Storage](https://github.com/vicboma1/loaderDumpsArcade#cache-storage-1)
### [Display](https://github.com/vicboma1/loaderDumpsArcade#display-1)
### [Rotation Display](https://github.com/vicboma1/loaderDumpsArcade#rotation-display-1)
### [TaskBar Menu](https://github.com/vicboma1/loaderDumpsArcade#taskbar-menu-1)
### [GUI](https://github.com/vicboma1/loaderDumpsArcade#gui)
### [Systems/Games Loaders](https://github.com/vicboma1/loaderDumpsArcade#systemsgames-loaders-wip)
* [Taito Type x](https://github.com/vicboma1/loaderDumpsArcade#taito-type-x-1)
* [Taito Type x2](https://github.com/vicboma1/loaderDumpsArcade#taito-type-x2-1)
* [NESiCAxLive](https://github.com/vicboma1/loaderDumpsArcade#nesicaxlive-1)
### [Video DevList](https://github.com/vicboma1/loaderDumpsArcade#dev-video-devlist-1)
### [Code Ratio](https://github.com/vicboma1/loaderDumpsArcade#code-ratio)
### [Highlights](https://github.com/vicboma1/loaderDumpsArcade#highlights-1)
### [References](https://github.com/vicboma1/loaderDumpsArcade#references-1)
### [About](https://github.com/vicboma1/loaderDumpsArcade#about-1)



## Systems
 
 ### Taito Type x
    ```
    Year : 2005
    CPU : Celeron - Pentium 4
    Chipset: Intel 865G
    GPU: ATI Radeon 9600SE/9600XT(128 MB) / X700PRO (256 MB), Bahia AGP 2.0/3.0 Soporte 1x/4x/8x
    SO: Windows XP Embedded
    ```
    
### Taito Type x2
  ```
    Year : 2005
    CPU : Intel Core 2 Duo E6400／Pentium 4 651／Celeron D 352
    Chipset: Intel Q965 + ICH8
    GPU: ATI RADEON X1600Pro/X1300LE o nVIDIA GeForce 7900GS／7600GS／7300GS
    SO: Microsoft Windows XP Embedded SP2
  ```

### NESiCAxLive
  ```
    Arcade System Board
    Run w/ Taito Type X, X2, X Zero, X3 and X4
  ```
  
## Loader | [Based on Injection's](https://github.com/vicboma1/Inject-DLL#process)
   ```C
   Boolean isLoaded { get; }
   Boolean isActive();
   int Open(String name);
   Task OpenAsync(String name);
   Kernel32Native.PROCESS_INFORMATION Create(String name, uint securityAttr);
   Boolean Attach(String name);
   Boolean InjectDLL(String name);
   List<IntPtr> SuspendAllThreads();
   Boolean ReadMemory(IntPtr processID, IntPtr address, int numOfBytes, byte[] buffer, out int bytesRead);
   Boolean WriteMemory(IntPtr hProc, IntPtr address, byte [] buffer, out int bytesWrited);
   List<IntPtr> ResumeAllThreads();
   Boolean Terminate();
   ```
   
## Inputs


### [GetAsyncKeyState](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-getasynckeystate) | [OpCodes](https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes)

#### Example | [File.properties](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Inputs/AsyncKeyState/readme.md)

* Player 1
 ```
 P1_SERVICE = 3
 P1_START = 1
 P1_COIN = 5
 P1_UP = UP
 P1_DOWN = DOWN
 P1_LEFT = LEFT
 P1_RIGHT = ALT
 P1_BUTTON_1 = SPACE
 P1_BUTTON_2 = CTRL
 P1_BUTTON_3 = C
 P1_BUTTON_4 = A
 P1_BUTTON_5 = V
 P1_BUTTON_6 = B
 ```
  
* Player 2
 ```
 P2_SERVICE = 4
 P2_START = 2
 P2_COIN = 6
 P2_UP = R
 P2_DOWN = F
 P2_LEFT = G
 P2_RIGHT = D
 P2_BUTTON_1 = A
 P2_BUTTON_2 = S
 P2_BUTTON_3 = E
 P2_BUTTON_4 = Q
 P2_BUTTON_5 = W
 P2_BUTTON_6 = E	
 ```
  
 * Board
 ```
 TEST_TILT1 = 3
 TEST_TILT2 = 7 
 TEST_TILT3 = 8
 TEST_MODE = T
 EXIT_CODE = ESC
 ```
 
 * Manual
 ```
 Need for the taito type x game to read the keyboard input 
 
 ENUM = Ascii code keyboard
 ```
  
### Direct Input | [Based on Hook's](https://github.com/vicboma1/Inject-DLL#hooks) | [DIKCodes](http://www.flint.jp/misc/?q=dik&lang=en)
 
#### Example | File.bin

 * Player 1
 ```
   [Display address]  [Value]  [Byte]  [Key]
   0000000000000000     00       .     Start
   0000000000000004     00       .     Coin
   0000000000000008     00       .     Service
   000000000000000C     00       .     Up
   0000000000000010     00       .     Down
   0000000000000014     00       .     Left
   0000000000000018     00       .     Right
   000000000000001C     00       .     Btn 1
   0000000000000020     00       .     Btn 2
   0000000000000024     00       .     Btn 3
   0000000000000028     00       .     Btn 4
   000000000000002C     00       .     Btn 5 
   0000000000000030     00       .     Btn 6
 ```
    
* Player 2
 ```
  [Display address]  [Value]  [Byte]  [Key] 
  0000000000000034     00       .     Start
  0000000000000038     00       .     Coin
  000000000000003C     00       .     Service
  0000000000000040     00       .     Up
  0000000000000044     00       .     Down
  0000000000000048     00       .     Left
  000000000000004C     00       .     Right
  0000000000000050     00       .     Btn 1
  0000000000000054     00       .     Btn 2
  0000000000000058     00       .     Btn 3
  000000000000005C     00       .     Btn 4
  0000000000000060     00       .     Btn 5 
  0000000000000064     00       .     Btn 6
 ```

* Board 
 ```
  [Display address]  [Value]  [Byte]  [Key]
  0000000000000068     00       .     Test Mode
  000000000000006C     00       .     Exit
 ```
  
* Manual 
 ```
  Need for the taito type x game to read the keyboard input 
  
  Keyboard    -  256 (short)
  0x000000XX     XX     
    
  Joystick    -  X[1|2]   -  Axis[+|-][X|Y|Z]   -  256 (btn)
  0xZXYA0CMN       ZY     -        YA           -    0CMN      
  
 
  Example
 
  [Display address]        [Hexa Code]             [Hexa Code]          [Ascii Code]
  0000000000000000  02 00 00 00 06 00 00 00  06 00 00 00 C8 00 00 00  ................
  0000000000000010  D0 00 00 00 CB 00 00 00  CD 00 00 00 02 00 00 00  ................
  0000000000000020  03 00 00 00 04 00 00 00  05 00 00 00 06 00 00 00  ................
  0000000000000030  07 00 00 00 32 00 00 00  31 00 00 00 30 00 00 00  ....2...1...0...
  0000000000000040  2F 00 00 00 2E 00 00 00  01 00 00 X1 03 00 00 X1  /...............
  0000000000000050  02 00 00 X1 25 00 00 00  24 00 00 00 23 00 00 00  ........$...#...
  0000000000000060  22 00 00 00 21 00 00 00  14 00 00 00 01 00 00 00  "...!...........         
 ```
   
* Input Tool to map output file *.bin

  ![](https://raw.githubusercontent.com/vicboma1/loaderDumpsArcade/master/assets/images/keyInputMappingAsyncV2.gif)
  
  
## JVS I/O Emulation

### [OpCodes](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/Protocol/JVS/JVSEnums.h)
#### Semantic Trace
```
Inicializando
	Logger: 2019-06-07_00-48-04-LoggerJvs.log 

	Escribo  6 bytes... -> [ E0 FF 03 F0 D9 CB ] 0xE0FF03F0D9CB
	[E0] = SYNC_CODE OK
	[FF] = BROADCAST A TODOS LOS NODOS
	[03] = 
	[F0] = RESET ALL NODES
	[D9] 
	[CB] = 
	Envío    0 bytes... -> [ ]

............................

	Escribo  6 bytes... -> [ E0 FF 03 F1 01 F4 ] 0xE0FF03F101F4
	[E0] = SYNC_CODE OK
	[FF] = BROADCAST A TODOS LOS NODOS
	[03] = 
	[F1] = Set Address
	[01] 
	[F4] = 
	Envío    6 bytes... -> [ XXXXXXXXXXX ]

............................

	Escribo  5 bytes... -> [ E0 01 02 10 13 ]  0xE001021013 
	[E0] = SYNC_CODE OK
	[01] = ESCLAVO
	[02] = 
	[10] = I/O IDENTIFICADOR 
	[13] = 
	Envío    58 bytes... -> [ XXXXXXXXXXX ]

............................

	Escribo  5 bytes... -> [ E0 01 02 11 14 ] 0xE001021114 
	[E0] = SYNC_CODE OK
	[01] = ESCLAVO
	[02] = 
	[11] = COMANDO REVISION FORMATO 
	[14] = 
	Envío    7 bytes... -> [ XXXXXXXXXXX ]
	
	...
	

............................
	
	Escribo  5 bytes... -> [ E0 00 02 00 02 ]
	[E0] = SYNC_CODE OK
	[00] = MAESTRO
	[02] =
	[00] = RESETEANDO MAQUINA (Exit Game)
	[02] = 
	Envío    6 bytes... -> [ XXXXXXXXXXX ]
```

## Graphics
 * Color Inverting per-stage texture processing
 * No filter stretch
 * Fetch stream vertex
 * Primitives to render
 * Rendered entities without alpha
 * Filters in runtime
 * Reverse pixel mode in runtime / Nearest-Point
 * Diffuse CyberPunk Lights
 * Spot Light Type
 * Anisotropic Filter

## Sound
 * Sound Create
 * Sound Capture 
 * Sound Full Duplex
 * Sound Full Duplex Create
 * Sound EnumerateA
 * Sound EnumerateW
 * Sound Buffer

## Virtual Storage
 * Dynamic virtual Hard Disk (VHD)
 * Substitute a drive letter for local path

## Cache Storage
 * Save/Config0000.bin
 * setting.dat
 * hiscore.dat
 * game.dat
 
## Display
 * Windowed
 * Windowed Center
 * Fullscreen (Windowed Magnifier)
 * Fullscreen Native
 
## Rotation Display
 * 0°
 * 90°
 * 180°
 * 270°

## TaskBar Menu
 * Show
 * Hidden
 * Animation

##  GUI

* scratch (Pof with vs2010) (wip)
   
   ![](https://raw.githubusercontent.com/vicboma1/loaderDumpsArcade/master/assets/images/GUI_v.0.0.1.gif)
  
## Systems/Games Loaders (wip)

### Taito Type x

<p align="center">
    <img src="assets/images/logo_mahjong.png" >
</p>

* [Cosplay 3D Mahjong - 706]() - Working Video | Inputs (WIP)

<p align="center">
    <img src="assets/images/logo_rastan.png" >
</p>

* [Rastan Saga (ラスタンサーガ) Arcade (2014) - 882 | Working 100%](https://youtu.be/pGB89NVwNDg) 
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/rastanSagattx.gif" width="800" height="480" />

<p align="center">
    <img src="assets/images/logo_raiden3.png" align="center" height="200" width="350">
</p>

* [Raiden III (雷電III, Raiden Surī) Arcade (2005) | Working 100%](https://www.youtube.com/watch?v=L5Bl5P3vHvo)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/raiden3_3.gif" width="800" height="480" />

* [Raiden III (雷電III, Raiden Surī) Arcade (2005) | Filters in Runtime | Working 100%](https://youtu.be/wKgiJ981Utw) 
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/raiden32.gif" width="800" height="480" />

* [Raiden III (雷電III, Raiden Surī) Arcade (2005) | Creating a voxel Hack which cancels the inner toplights for the main sprite | Working 100%](https://youtu.be/1fW33Jc9ZZ8) 
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/Raiden3_Light_60_.gif" width="800" height="480" />

<p align="center">
    <img src="assets/images/logo_raiden4.png" align="center" height="150" width="450">
</p>

* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) | Intro gameplay](https://youtu.be/byBMfUstYLY) 
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/Raiden4_intro_60_.gif" width="800" height="480" />

* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) | Working 100% | 60 fps](https://youtu.be/WWz7wMm-rPA) 
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/Raiden4_gameplay_60_fps2.gif" width="800" height="480" />

* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) | Alpha Blending | 60 fps](https://www.youtube.com/playlist?list=PLNph7ndeSqE9Dtq5gqllBOdRElYEQfLrr) 
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/Raiden4_alpha_60_fps.gif" width="800" height="480" />

<p align="center">
    <img src="assets/images/logo_homura.png" align="center" height="100" width="300">
</p>

* [Homura (ほむら) Arcade (2005) | Working 100% ](https://youtu.be/ZulUZrCqbTM)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/homuraL1.gif" width="800" height="480" />

* [Homura (ほむら) Arcade (2005) | Stretch Rendered | Working 100% ](https://youtu.be/ZulUZrCqbTM)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/ezgif-1-5a6971de372c.gif" width="800" height="480" />

* [Homura (ほむら) Arcade (2005) | Invert Color Texture | Working 100% ](https://youtu.be/Yj7jjW3M0xc)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/HL1_invert.gif" width="800" height="480" />

<p align="center">
    <img src="assets/images/logo_chaosBreaker.jpg" align="center" height="125" width="300">
</p>

* [Chaos Breaker (カオスブレイカー) Arcade (2004) - Taito Type X | Windowed HD](https://youtu.be/y-PWoBVzcZU)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/CB_HD.gif" width="800" height="480" />

* [Chaos Breaker (カオスブレイカー) Arcade (2004) - Taito Type X | Invert Color](https://youtu.be/heXYJ6bYnkM)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/CB_I.gif" width="800" height="480" />

<p align="center">
    <img src="assets/images/logo_gigawings.png" align="center" height="125" width="300">
</p>

* [Giga wing Generation (翼神ギガウイング ジェネレーションズ) Arcade (2004) - Taito Type X | Windowed Mode](https://youtu.be/C3unm3GpX-Q)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/gwg3.gif" width="800" height="480" />

* [Giga wing Generation (翼神ギガウイング ジェネレーションズ) Arcade (2004) - Taito Type X | Working 100%](https://youtu.be/qh9ARTth-NA)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/gwg4.gif" width="800" height="480" />


<p align="center">
    <img src="assets/images/logo_TGM3.png" align="center" height="200" width="350">
</p>

* [Tetris The Grand Master 3 Terror Instinct / TGM3 (の認定モードに挑戦のムービー) Arcade (2005)](https://youtu.be/7vc35kFPJvY)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/TGM3.gif" width="800" height="480" />

<p align="center">
    <img src="assets/images/log_spica.png" align="center" height="200" width="350">
</p>

* [Spica Adventure (スピカアドベンチャー) - Arcade (2005) | Windowed Mode](https://youtu.be/0atLTgOaOIk )
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/spicaAdventureArcade.gif" width="800" height="480" />

* [Spica Adventure (スピカアドベンチャー) - Arcade (2005) | Fullscreen Mode](https://youtu.be/VxmwMzMFHwY )
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/spicaAdventureBoss.gif" width="800" height="480" />

### Taito Type x2

<p align="center">
    <img src="assets/images/logo_troublewitches.png" align="center" height="150" width="400">
</p>


* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) | Working 100%](https://youtu.be/d0Eo7ataLvg)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/troubleWitches5.gif" width="800" height="480" />

* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008)| Hack Hidden Background | Working 100%](https://youtu.be/ZytAryfM6Y0)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/brujasHack2_600.gif" width="800" height="480" />

* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) | Rendered entities without alpha | Working 100%](https://www.youtube.com/watch?v=hwjk6pUyw8g)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/_h2_hd.gif" width="800" height="480" />

* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) | Stretch Rendered | Working 100%](https://www.youtube.com/watch?v=WdVXEIHrdOE)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/brujas2hachstretch.gif" width="800" height="480" />

### NesicaxLive
* [Cosplay 3D Mahjong - 401300]() - Video (WIP)
* [Rastan Saga - 401500]() - Inputs (WIP)
* [Puzzle Bobble - 301200 ]() - Inputs (WIP)

<p align="center">
    <img src="assets/images/logo_elevator.png" align="center" height="150" width="400">
</p>

* [Elevator Action (エレベーターアクション) - Arcade (2014) | Windowed Hack](https://youtu.be/dPL_xJyc9C8) 
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/elevatoraction.gif" width="800" height="480" />

* [Elevator Action (エレベーターアクション) - Arcade (2014) | Fullscreen Hack NesicaxLive](https://youtu.be/aPLpg5CJqGY )
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/elevatoractionF.gif" width="800" height="480" />


# [Video DevList](https://www.youtube.com/playlist?list=PLNph7ndeSqE-ipUjV17uCQ-ZMGs9VC7CH)

* [Elevator Action (エレベーターアクション) - Arcade (2014) | Fullscreen Hack NesicaxLive](https://youtu.be/aPLpg5CJqGY)
* [Elevator Action (エレベーターアクション) - Arcade (2014) | Windowed Hack NesicaxLive](https://youtu.be/dPL_xJyc9C8)
* [Spica Adventure (スピカアドベンチャー) - Arcade (2005) | Level 3 - Space Invader Boss](https://youtu.be/VxmwMzMFHwY)
* [Spica Adventure (スピカアドベンチャー) - Arcade (2005) | Fullscreen Mode](https://youtu.be/24xwVvKhKUs)
* [Spica Adventure (スピカアドベンチャー) - Arcade (2005) | Windowed Mode](https://youtu.be/0atLTgOaOIk )
* [Tetris The Grand Master 3 Terror Instinct / TGM3 (の認定モードに挑戦のムービー) Arcade (2005) | Fullscreen Mode](https://youtu.be/7vc35kFPJvY)
* [Tetris The Grand Master 3 Terror Instinct / TGM3 (の認定モードに挑戦のムービー) Arcade (2005) | Fullscreen w/Border](https://youtu.be/XyL1E2oFUNE)
* [Tetris The Grand Master 3 Terror Instinct / TGM3 (の認定モードに挑戦のムービー) Arcade (2005) | Windowed Mode](https://youtu.be/DxavhhYSmpE )
* [Tetris The Grand Master 3 Terror Instinct / TGM3 (の認定モードに挑戦のムービー) Arcade (2005) | Viewport Hacking](https://youtu.be/WA80-iZ062w )
* [Tetris The Grand Master 3 Terror Instinct / TGM3 (の認定モードに挑戦のムービー) Arcade (2005) | Game Hacking](https://youtu.be/YPl0_GEEgik)
* [Giga wing Generation (翼神ギガウイング ジェネレーションズ) Arcade (2004) - Taito Type X | Longplay GameHacking]( https://youtu.be/qh9ARTth-NA)
* [Giga wing Generation (翼神ギガウイング ジェネレーションズ) Arcade (2004) - Taito Type X | Bad Stencil Graphic](https://youtu.be/ek1_2ivwp70 )
* [Giga wing Generation (翼神ギガウイング ジェネレーションズ) Arcade (2004) - Taito Type X | Windowed Mode](https://youtu.be/C3unm3GpX-Q)
* [Chaos Breaker (カオスブレイカー) Arcade (2004) - Taito Type X | Working 100% Stage 3-4](https://youtu.be/T3URlwacrdk)
* [Chaos Breaker (カオスブレイカー) Arcade (2004) - Taito Type X | Working 100% Stage 1-2](https://youtu.be/4M54WQgAMu0)
* [Raiden IV (雷電IV Raiden Fō) Arcade 2007 Taito Type X | Anisotropico Filter](https://youtu.be/hFtfWKUp-tw)
* [Raiden IV (雷電IV Raiden Fō) Arcade 2007 Taito Type X | Invert Colors](https://youtu.be/KwUDml91B7g)
* [Chaos Breaker (カオスブレイカー) Arcade (2004) - Taito Type X | Anisotropico Filter](https://www.youtube.com/watch?v=yyglkZDB6U8)
* [Chaos Breaker (カオスブレイカー) Arcade (2004) - Taito Type X | Invert Color](https://youtu.be/heXYJ6bYnkM)
* [Chaos Breaker (カオスブレイカー) Arcade (2004) - Taito Type X | Improving 60FPS](https://youtu.be/tPvLwHai0ME)
* [Chaos Breaker (カオスブレイカー) Arcade (2004) - Taito Type X | Fullscreen](https://youtu.be/_NgRjtBGzIU)
* [Chaos Breaker (カオスブレイカー) Arcade (2004) - Taito Type X | Windowed HD](https://youtu.be/y-PWoBVzcZU)
* [Chaos Breaker (カオスブレイカー) Arcade (2004) - Taito Type X | Windowed Mode](https://youtu.be/5VerBuQEkcU)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Intro Gameplay Fixed](https://youtu.be/jh4URJZgbbo)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | Intro Gameplay Fixed ](https://youtu.be/2cBvG9guv68)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Level 2 Invert color texture ](https://youtu.be/AaY-lbOMRHU)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Level 1 Invert color texture ](https://youtu.be/Yj7jjW3M0xc)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Fixing game exit](https://youtu.be/8kmfgJgGs90)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Fixing Back buffer](https://youtu.be/EzyGZH9q7PQ)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Level 4](https://youtu.be/CueDP9Eo2F0)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Level 3](https://youtu.be/J_44bRZj10k)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Level 2](https://youtu.be/K7ml_DnExFg)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Level 2 Hack Stretch Rendered](https://youtu.be/yAC5v9YL1Vk)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Level 1 ](https://youtu.be/ZulUZrCqbTM)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Fullscreen Rotation 90° - 60 FPS](https://youtu.be/iaOecZxfWU4)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Fullscreen Rotation 90° - Bad FPS...](https://youtu.be/Fe_goXXkpM4)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Windowed](https://youtu.be/42s62PBZFDs)
* [Homura (ほむら) Arcade (2005) - Taito Type x | Hooking Video](https://youtu.be/TRQ8mhcG3n0)
* [Launcher Sync vs Async](https://youtu.be/v1pjWTGenAc)
* [Launcher Async + Destroyer Process + Modularity addons](https://youtu.be/VTdmDnnGWlA)
* [Loader & Demon - Capture Process w ThreadKernel](https://youtu.be/s7Lad-j6L2o)
* [VHD vs SUBST to mount a drive letter](https://youtu.be/YLcdkaPVlgw)
* [Substitute a drive letter for local path](https://youtu.be/jsZaTRLHZ0k)
* [Hooking - Capturing pop-up window when mounting a VHD in runtime](https://youtu.be/uPD4WT60gv4)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | Alpha Blending Longplay](https://youtu.be/l4f-RL1lFWg)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Alpha Blending Level-5](https://youtu.be/OWQjTKIyIYs)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Alpha Blending Level-4](https://youtu.be/fXngq9ocQlw)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Alpha Blending Level-3](https://youtu.be/_GxWZOsMh3w)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Alpha Blending Level-2](https://youtu.be/jeKVfM5r6l0)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Alpha Blending Level-1](https://youtu.be/pnU_iFDJB1g)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Alpha Blending Longplay](https://youtu.be/WVF5NIfcazw)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Fullscreen 60 fps ](https://youtu.be/UbR_rJappac)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Working 100% | 60 fps](https://youtu.be/WWz7wMm-rPA)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Demostration gamePlay](https://youtu.be/cGrcoSgKhCY)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Automatic virtual disk](http://www.youtube.com/watch?v=H7lU8WMDZrY)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Partition disk D](http://www.youtube.com/watch?v=sNqQlEhafkM)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Fullscreen & Rotation Display](https://youtu.be/byBMfUstYLY)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Windowed](https://youtu.be/KSZ0gIxmzU0)
* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) - Taito Type X | Error Direct3Dバックバッファ取得失敗](https://youtu.be/wXJ1pOcU54E)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | Spot Light Type](https://youtu.be/1fW33Jc9ZZ8)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | Diffuse CyberPunk Lights](https://youtu.be/wBOByMJZJb4)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) - Taito Type x2 | Texture Filtering in runtime | Nearest-Point](https://youtu.be/QmNS6zFTKpg)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | Reverse pixel mode in runtime](https://youtu.be/x2dFOSd8rVI)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | Filters in runtime](https://youtu.be/L5Bl5P3vHvo)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | Working 100% ](https://youtu.be/CqVhs1MV7fc)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | Rendered entities without alpha](https://youtu.be/YXoffBoCQFA)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | Rotation Native Screen 90º](https://youtu.be/OJDhNMZ-WDA)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | Proof of concept screen rotation 0 - 90 - 180 - 270](https://youtu.be/GdglTFiwsGk)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | Working 100% ](https://youtu.be/d0Eo7ataLvg)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | Primitives to render ](https://youtu.be/1BOFofAWJCQ)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | Fetch stream vertex](https://youtu.be/2GzN8lyw67s)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | Utils bad text rendering ](https://youtu.be/_bpLo6YR2-A)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | No filter stretch](https://youtu.be/WdVXEIHrdOE)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | Hidden background](https://youtu.be/ZytAryfM6Y0)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | JVS working](https://youtu.be/ApofTCfae-Y)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | Hooking Display](https://youtu.be/0MQ7qit3hw0)
* [Raiden III (雷電III, Raiden Surī) Arcade (2005) - Taito Type x | I/O Error PC](https://youtu.be/wKgiJ981Utw)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) - Taito Type x2 | JVS I/O Coin Error overflow w/ +40000 credits ](https://youtu.be/bXRC05W12IY)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | Test Mode input mapping w/JVS I/O](https://youtu.be/FkcUcNCo7BI)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | Mapping input async](https://youtu.be/mXoh5oKt39w)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | JVS I/O Error](https://youtu.be/mXoh5oKt39w)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | Speed video](https://youtu.be/yyUQgcxYnqA)
* [Trouble Witches AC (トラブル☆ウィッチーズＡＣ) Arcade (2008) - Taito Type x2 | Solved JVS I/O ERROR (00)](https://youtu.be/eEW_f5E4UAw)
* [Rastan Saga (ラスタンサーガ) Arcade (2014) - Taito Type x | Windowed size Optimization](https://youtu.be/7OtyeKExRcU)
* [Rastan Saga (ラスタンサーガ) Arcade (2014) - Taito Type x | icon set hwnd](https://youtu.be/Rcl8FS5NELs)
* [Rastan Saga (ラスタンサーガ) Arcade (2014) - Taito Type x | Windowed screen](https://youtu.be/PjmyWyBUKKs)
* [Rastan Saga (ラスタンサーガ) Arcade (2014) - Taito Type x | Hook input keyboard](https://youtu.be/uG3ttaLP6Z0)
* [Rastan Saga (ラスタンサーガ) Arcade (2014) - Taito Type x | Directx vertical hooking](https://youtu.be/n9h24hYXedQ)
* [Rastan Saga (ラスタンサーガ) Arcade (2014) - Taito Type x | Directx size hooking](https://youtu.be/7KRQW63Cxtw)
* [Rastan Saga (ラスタンサーガ) Arcade (2014) - Taito Type x | Directx Display hooking II](https://youtu.be/ZvJ_Y1MpI3U)
* [Rastan Saga (ラスタンサーガ) Arcade (2014) - Taito Type x | Directx Display hooking I](https://youtu.be/VEUg6j_JLqw)
* [Inject Dll - Remote thread](https://youtu.be/8mL-wPzPZHw)
* [Api Hook - MessageBox | 32bits](https://youtu.be/kHs7gUDr03s)
* [Api Hook - Keyboard Async GUI | 32bits](https://youtu.be/Agw_1XLF7fY)
* [Inject Dll - Interoperabilidad entre C# y C Nativo (APIENTRY DllMain)](https://youtu.be/zQpBnYENabU)
* [Inject Dll - Suspend & Resume](https://youtu.be/A59-xcBp3Mo)
* [Inject Dll - Suspend Process](https://youtu.be/K2dtFfwR12Q)
* [Inject Dll - Capture Handlers](https://youtu.be/51Dj0L7bFiw)
* [Launcher Process Async](https://youtu.be/gVZMo1s0FPE)


# Code Ratio

```
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
XML                            142            173            345         286219
C/C++ Header                   795          38483          84272         147221
C++                            114           4477           4607          16206
C                               14            747            711          10235
C#                             118           1478           3894           9043
MSBuild script                  18              0             49           1653
Markdown                         3              4              0             46
DOS Batch                        8              1              0             27
XAML                             2              1              0             15
JSON                             5              0              0              5
Bourne Shell                     2              7             22              4
Assembly                         1              1              2              1
-------------------------------------------------------------------------------
SUM:                          1222          45372          93902         470675
-------------------------------------------------------------------------------
```

# Highlights
 * [Retrogaming: Una misión posible en sistemas Arcade de nueva generación - Retropolis 2019](https://www.inf.upv.es/www/etsinf/es/retropolis-valencia-2019-regresa-el-sabado-4-de-mayo-a-etsinf/)
 * [Podcast Taberna Nintendera - T02E16 - 037 - Programa 12_05_2019](https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/audio/vlc-record-2019-12-25-22h03m56s-Taberna-Nintendera-T02E16-037-Programa-12_05_2019-.mp3)
 
# References
 * [JVS vs JAMMA](http://forum.arcadecontrols.com/index.php?topic=95942.0)
 * [JVS conversion](https://wiki.arcadeotaku.com/images/9/97/SEGA_cabinet_JVS_conversion_manual_.pdf)
 * [JVS protocols](https://wiki.arcadeotaku.com/w/JVS)
 * [Jamma Video Standard](http://daifukkat.su/files/jvs_wip.pdf)
 * [Naomi I/O Board](https://wiki.arcadeotaku.com/images/d/db/Capcom_io_jp_manual.pdf)
 * [Manual Programmer NV API ](https://github.com/vicboma1/loaderDumpsArcade/raw/master/assets/images/NVControlPanel_API.pdf)
 * [JVS](http://superusr.free.fr/arcade/JVS/JVST_VER3.pdf)
 * [JVS Original](https://github.com/vicboma1/loaderDumpsArcade/raw/master/assets/images/JVSR.pdf)
 * [I/O Board](https://github.com/reicast/reicast-emulator/blob/master/core/hw/maple/maple_devs.cpp)
 * [Input Keys](http://www.flint.jp/misc/?q=dik&lang=en)
 * [Cloc](https://es.osdn.net/projects/sfnet_cloc/)
 * [Use DLL Native with C/C++ in C# Project](https://mark-borg.github.io/blog/2017/interop/)
 * [Function Pointers](https://www.codeproject.com/Articles/7150/Member-Function-Pointers-and-the-Fastest-Possible)
 * [Windows Native API - Roger Orr [ACCU 2019]](https://www.youtube.com/watch?v=a0KozcRhotM)
 * [Previous Mode](https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/previousmode?redirectedfrom=MSDN)
 * [Kernel Native](https://www.geoffchappell.com/studies/windows/km/ntoskrnl/api/index.htm)
 * [C++ : Gestión de memoria con std::unique_ptr (Smart Pointers)](https://www.youtube.com/watch?v=MSk__71a41Q)
 * [Game System Requirements](https://github.com/vicboma1/loaderDumpsArcade/tree/master/assets/Documentation/Games)
 
# About

Loader Dump Arcade is programmed by vicboma1, all this is a homebrew development with reverse engineering, non official technical documentation and a lot of personal time.
 
Twitter : https://twitter.com/vicboma1.

This software is provided as-is, and is licensed under the MIT License. 

```
MIT License

Copyright (c) 2019 Victor Bolinches

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

# No roms, no games, no dumps! 
