/**************************************************

Behold TV v5.xx Windows messages API

Support:
http://www.beholder.ru
mailto:support@beholder.ru

***************************************************

Examples {������� �������������}:

Find handle for send message to application {����� ����� �� ��� ������� ���������} -

HWND hBhWnd = FindWindow ("TMain", "BeholdTV");


Exit {����� �� ��} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_EXIT, NULL);
or {���}
	PostMessage(hBhWnd, WM_CLOSE, NULL, NULL);


Increase main volume {��������� ���������} - 
	PostMessage(hBhWnd, WM_BHCMD, WMBH_VOLUMEUP, NULL);

Decrease main volume {��������� ���������} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_VOLUMEDOWN, NULL);

Increase Brightness Up {��������� �������} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_SELVOLMODE, NULL);    // select brightness {����� �������}
	PostMessage(hBhWnd, WM_BHCMD, WMBH_VOLUMEUP, NULL);      // increase brighthess {��������� �������}
or {���}
Set Brightness value = 120 {���������� ������� = 120}
	PostMessage(hBhWnd, WM_BHCMD, WMBH_SETBRITN, 120);

Toggle Mute/Unmute {������� ���������-�������� ����} - 
	PostMessage(hBhWnd, WM_BHCMD, WMBH_MUTE, NULL);

Switch to channel #12 {����������� �� 12 �����}  -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_CHNLN, 12);

Switch channel Up {����������� �� ��������� �����} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_CHNLUP, NULL);

Switch channel Down {����������� �� ���������� �����} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_CHNLDOWN, NULL);

Toggle Start/Stop video record {������� ���������/���������� �����������} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_RECV, NULL);
or {���}
Start video record {��������� �����������} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_RECVSTART, NULL);

Stop video record {���������� �����������}-
	PostMessage(hBhWnd, WM_BHCMD, WMBH_RECVSTOP, NULL);

Get version of Behold TV {�������� ����� ������ ��} -
	DWORD dwVer = (DWORD) SendMessage(hBhWnd, WM_BHCMD, WMBH_GETVERSION, NULL);
	if (HIWORD(dwVer) == 4 && LOWORD(dwVer) == 58)
	{
		// this is version 4.58
	}

Get volume {�������� ������� ������� ���������} -
	WORD wVol = (WORD) SendMessage(hBhWnd, WM_BHCMD, WMBH_GETVOLUME, NULL);


****************************************************/


#ifndef __BHMSG_H__
#define __BHMSG_H__

#pragma once


#define  WM_BHCMD            WM_USER+200	

#define  WMBH_CHNLN          WM_USER+201	//  Switch to absolute channel number (LParam = 1..999) {����������� �� ����� � ���������� ���������� �������}
#define  WMBH_CHNLMODE       WM_USER+202	//  Toggle channel's number select mode (-, --, ---) {����� ������ ������ ������}
#define  WMBH_CHNLUP         WM_USER+203	//  Switch channel Up {����������� �� ��������� �����}
#define  WMBH_CHNLDOWN       WM_USER+204	//  Switch channel Down {����������� �� ���������� �����}
#define  WMBH_CHNLRECALL     WM_USER+205	//  Recall previous channel {������� ����������� ������}
#define  WMBH_CHNLGETINFO    WM_USER+206	//  Get current channel's info {�������� � OSD ���������� � ������}

// Compatible with version 4.70 and higher 
#define  WMBH_CHNL_09        WM_USER+207	//  Call button number 0-9 to switch channel with WMBH_CHNLMODE rule (LParam = 0..9) {������� ������� ������ �� 0 �� 9 ��� ������������ ������ �� ������� �������������� � WMBH_CHNLMODE}
// Compatible with version 4.70 and higher

#define  WMBH_VOLUMEUP       WM_USER+210	//  Set level (volume) up {��������� ��������� �������}
#define  WMBH_VOLUMEDOWN     WM_USER+211	//  Set level (volume) down {��������� ��������� �������}
#define  WMBH_SELVOLMODE     WM_USER+212	//  Toggle mode for change level (Brightness, Contrast, Hue, Saturation, Sharpness, Gain) {������� ������ ������� ����������� ������}
#define  WMBH_MUTE           WM_USER+213	//  Toggle Mute/UnMute {������� ���������-�������� ����}
#define  WMBH_SETBRITN       WM_USER+214	//  Set Britness level   (LParam = 0..255) {���������� �������� �������}
#define  WMBH_SETCONTR       WM_USER+215	//  Set Contrast level   (LParam = 0..127) {���������� �������� �������������}
#define  WMBH_SETSAT         WM_USER+216	//  Set Saturation level (LParam = 0..127) {���������� �������� ������������ �����}
#define  WMBH_SETHUE         WM_USER+217	//  Set Hue level        (LParam = -128..127) {���������� �������� ������� �����}
#define  WMBH_SETSHR         WM_USER+218	//  Set Sharpness level  (LParam = -8..7) {���������� �������� ��������}
#define  WMBH_SETGAIN        WM_USER+219	//  Set Video Gain level (LParam = 0..300) {���������� �������� ������ �������������}

#define  WMBH_CHANGESOURCE   WM_USER+220	//  Toggle modes (TV/FM/AV) {������� ������������ ������� ��}
#define  WMBH_CHANGETVFM     WM_USER+221	//  Toggle modes TV/FM {������� ������������ ������� TV/FM}
#define  WMBH_CHANGETV       WM_USER+222	//  Select TV mode {����������� � ����� TV}
#define  WMBH_CHANGEFM       WM_USER+223	//  Select FM mode {����������� � ����� FM}
#define  WMBH_CHANGECVBS     WM_USER+224	//  Select AV-CVBS mode {����������� � ����� AV-CVBS}
#define  WMBH_CHANGESVID     WM_USER+225	//  Select AV-SVideo mode {����������� � ����� AV-SVideo}
// Compatible with version 5.00 and higher
#define  WMBH_CHANGEDVB      WM_USER+226	//  Toggle DVB/Analog modes {������� ������������ ������� ������ DVB/Analog}
// Compatible with version 5.00 and higher

#define  WMBH_FULLSCREEN     WM_USER+230	//  Toggle FullScreen/Window mode {������� ������������ ��������������-�������� ������}
#define  WMBH_SETONTOP       WM_USER+231	//  Toggle On/Off main panel Stay-OnTop mode {������� ������������ ������ ���� ���� ��� ������� ������}
#define  WMBH_FREEZE         WM_USER+232	//  Toggle On/Off freeze frame {������� ����-�����}
#define  WMBH_SETONTOPVW     WM_USER+233	//  Toggle On/Off video window Stay-OnTop mode {������� ������������ ������ ���� ���� ��� ���������}

#define  WMBH_TSSTART        WM_USER+234	//  Timeshift start {��������� ��������}
#define  WMBH_TSSTOP         WM_USER+235	//  Timeshift stop {���������� ��������}
#define  WMBH_TSPAUSE        WM_USER+236	//  Timeshift pause {������������� ��������}
#define  WMBH_TSCONTINUE     WM_USER+237	//  Timeshift continue {���������� ��������}
#define  WMBH_TSFORWARD      WM_USER+238	//  Timeshift step forward (LParam = step time in milliseconds, min. value = 5000) {��������� �������� �� ��� ������}
#define  WMBH_TSBACKWARD     WM_USER+239	//  Timeshift step backward (LParam = step time in milliseconds, min. value = 5000) {��������� �������� �� ��� �����}

#define  WMBH_RESETVIDEO     WM_USER+240	//  Reset video amplifier volume to default {�������� ��������� ������������ � �������� �� ���������}
#define  WMBH_SETA2CHNL      WM_USER+241	//  Change A2 CH1/CH2 or NICAM M1/M2 or BTSC SAP audio channels {�������� ����� ������ TV �������������}
#define  WMBH_SETSLEEP       WM_USER+242	//  Set sleep timer {��������� ������� �� ����������}

// Compatible with version 5.20 and higher
#define  WMBH_ZOOM_UP        WM_USER+244	//  Increase video zoom
#define  WMBH_ZOOM_DOWN      WM_USER+245	//  Decrease video zoom
#define  WMBH_ZOOM_VALUE     WM_USER+246	//  Set video zoom (LParam = zoom value in %, range -40..+50)
#define  WMBH_ASPECT_NEXT    WM_USER+248	//  Next video aspect ratio mode
#define  WMBH_ASPECT_VALUE   WM_USER+249	//  Set video aspect ratio mode (LParam = aspect mode, range 0..7) 
// Compatible with version 5.20 and higher

#define  WMBH_TELETEXT       WM_USER+250	//  Toggle On/Off teletext mode {������� ���������-���������� ������ ����������}
#define  WMBH_SURFING        WM_USER+251	//  Toggle Start/Stop channels surfing mosaic {������� ���������-���������� ������ ������� �������}
#define  WMBH_TVGUIDEC       WM_USER+252	//  Show current TVGuide program {�������� ������� ������������ � OSD}
#define  WMBH_TVGUIDEP       WM_USER+253	//  Show previous TVGuide program {�������� ���������� ������������ � OSD}
#define  WMBH_TVGUIDEN       WM_USER+254	//  Show next TVGuide program {�������� ��������� ������������ � OSD}

#define  WMBH_RECV           WM_USER+260	//  Toggle Start/Stop Video record {������� ���������-���������� �����������}
#define  WMBH_RECA           WM_USER+262	//  Toggle Start/Stop Audio record {������� ���������-���������� �����������}
#define  WMBH_RECSNAP        WM_USER+263	//  Make snapshot {������� ��������� ������}
#define  WMBH_RECSNAPM       WM_USER+264	//  Toggle Start/Stop Multi-snapshot {������� ���������-���������� ������������ ����� �������}
#define  WMBH_RECPAUSE       WM_USER+265	//  Toggle Pause/Continue any recording {������� �����-���������� ������}
#define  WMBH_RECLIMIT       WM_USER+266	//  Instant select record limit time {������� ����� ������ ������� ������}

#define  WMBH_RECVSTART      WM_USER+270	//  Start Video record {��������� �����������}
#define  WMBH_RECVSTOP       WM_USER+271	//  Stop Video record {���������� �����������}
#define  WMBH_RECASTART      WM_USER+274	//  Start Audio record {��������� �����������}
#define  WMBH_RECASTOP       WM_USER+275	//  Stop Audio record {���������� �����������}
#define  WMBH_RECMULTISTART  WM_USER+276	//  Start Multi-snapshot {��������� ������������ ����� �������}
#define  WMBH_RECMULTISTOP   WM_USER+277	//  Stop Multi-snapshot {���������� ������������ ����� �������}
#define  WMBH_RECPAUSEON     WM_USER+278	//  Set Pause for any recording {���������� ����� ������}
#define  WMBH_RECPAUSEOFF    WM_USER+279	//  Set Unpause for any recording {����� ����� ������}

#define  WMBH_SETVOLUME      WM_USER+280	//  Set sound volume level (LParam = 0..65535) {���������� ������� ���������}
#define  WMBH_GETVOLUME      WM_USER+281	//  Get sound volume level (Result = 0..65535), use SendMessage {�������� ������� ������� ���������}
#define  WMBH_SETMUTE        WM_USER+282	//  Set global sound mute/unmute (Mute: LParam = 1, Unmute: LParam = 0) {���������/�������� ���������� ����}

// Compatible with version 4.80 and higher
#define  WMBH_SETMUTESAFE    WM_USER+283	//  Set local sound mute/unmute (Mute: LParam = 1, Unmute: LParam = 0) {���������/�������� ��������� ����}
// Compatible with version 4.80 and higher

#define  WMBH_GETVERSION     WM_USER+285	//  Get version of Behold TV (see example), use SendMessage {�������� ����� ������ ��}
// Compatible with version 5.22 and higher
#define  WMBH_GETPLOCK       WM_USER+286	//  Get analog video VSYNC status or DVB Lock status, use SendMessage {�������� ������ ������� ������������ � ���������� ������ ��� ������ ������� ������������ � DVB ������}
#define  WMBH_GETCHNLN       WM_USER+287	//  Get current absolute channel number, use SendMessage {�������� ������� ���������� ����� ������}
// Compatible with version 5.22 and higher

#define  WMBH_SLEEPWAKE      WM_USER+290	//  Toggle sleep to tray/Wake up {������� �������� �� � ��������� ����-������������ � ���������� �����}
#define  WMBH_EXIT           WM_USER+291	//  Exit program {����� �� ��}
#define  WMBH_SUSPEND        WM_USER+292	//  Suspend Windows {��������� Windows � ������ �����}
#define  WMBH_HIBERNATE      WM_USER+293	//  Hibernate Windows {��������� Windows � ����� ��������� (������ �����)}
#define  WMBH_SHUTDOWN       WM_USER+294	//  Shutdown system {��������� ��������}

// Compatible with version 5.10 and higher
#define  WMBH_SLEEP          WM_USER+295	//  Sleep to tray {C������� �� � ��������� ����}
#define  WMBH_WAKE           WM_USER+296	//  Wake up from tray {������������ �� � ���������� ����� �� ����}
// Compatible with version 5.10 and higher


#endif
