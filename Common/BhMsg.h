/**************************************************

Behold TV v5.xx Windows messages API

Support:
http://www.beholder.ru
mailto:support@beholder.ru

***************************************************

Examples {Примеры использования}:

Find handle for send message to application {Найти хендл ПО для посылки сообщений} -

HWND hBhWnd = FindWindow ("TMain", "BeholdTV");


Exit {Выход из ПО} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_EXIT, NULL);
or {или}
	PostMessage(hBhWnd, WM_CLOSE, NULL, NULL);


Increase main volume {Увеличить громкость} - 
	PostMessage(hBhWnd, WM_BHCMD, WMBH_VOLUMEUP, NULL);

Decrease main volume {Уменьшить громкость} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_VOLUMEDOWN, NULL);

Increase Brightness Up {Увеличить яркость} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_SELVOLMODE, NULL);    // select brightness {выбор яркости}
	PostMessage(hBhWnd, WM_BHCMD, WMBH_VOLUMEUP, NULL);      // increase brighthess {увеличить яркость}
or {или}
Set Brightness value = 120 {Установить яркость = 120}
	PostMessage(hBhWnd, WM_BHCMD, WMBH_SETBRITN, 120);

Toggle Mute/Unmute {Триггер выключить-включить звук} - 
	PostMessage(hBhWnd, WM_BHCMD, WMBH_MUTE, NULL);

Switch to channel #12 {Переключить на 12 канал}  -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_CHNLN, 12);

Switch channel Up {Переключить на следующий канал} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_CHNLUP, NULL);

Switch channel Down {Переключить на предыдущий канал} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_CHNLDOWN, NULL);

Toggle Start/Stop video record {Триггер запустить/остановить видеозапись} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_RECV, NULL);
or {или}
Start video record {Запустить видеозапись} -
	PostMessage(hBhWnd, WM_BHCMD, WMBH_RECVSTART, NULL);

Stop video record {Остановить видеозапись}-
	PostMessage(hBhWnd, WM_BHCMD, WMBH_RECVSTOP, NULL);

Get version of Behold TV {Получить новер версии ПО} -
	DWORD dwVer = (DWORD) SendMessage(hBhWnd, WM_BHCMD, WMBH_GETVERSION, NULL);
	if (HIWORD(dwVer) == 4 && LOWORD(dwVer) == 58)
	{
		// this is version 4.58
	}

Get volume {Получить текущий уровень громкости} -
	WORD wVol = (WORD) SendMessage(hBhWnd, WM_BHCMD, WMBH_GETVOLUME, NULL);


****************************************************/


#ifndef __BHMSG_H__
#define __BHMSG_H__

#pragma once


#define  WM_BHCMD            WM_USER+200	

#define  WMBH_CHNLN          WM_USER+201	//  Switch to absolute channel number (LParam = 1..999) {Переключить на канал с абсолютным порядковым номером}
#define  WMBH_CHNLMODE       WM_USER+202	//  Toggle channel's number select mode (-, --, ---) {Режим набора номера канала}
#define  WMBH_CHNLUP         WM_USER+203	//  Switch channel Up {Переключить на следующий канал}
#define  WMBH_CHNLDOWN       WM_USER+204	//  Switch channel Down {Переключить на предыдущий канал}
#define  WMBH_CHNLRECALL     WM_USER+205	//  Recall previous channel {Возврат предыдущего канала}
#define  WMBH_CHNLGETINFO    WM_USER+206	//  Get current channel's info {Показать в OSD информацию о канале}

// Compatible with version 4.70 and higher 
#define  WMBH_CHNL_09        WM_USER+207	//  Call button number 0-9 to switch channel with WMBH_CHNLMODE rule (LParam = 0..9) {Вызвать нажатие кнопки от 0 до 9 для переключения канала по правилу установленному в WMBH_CHNLMODE}
// Compatible with version 4.70 and higher

#define  WMBH_VOLUMEUP       WM_USER+210	//  Set level (volume) up {Увеличить выбранный уровень}
#define  WMBH_VOLUMEDOWN     WM_USER+211	//  Set level (volume) down {Уменьшить выбранный уровень}
#define  WMBH_SELVOLMODE     WM_USER+212	//  Toggle mode for change level (Brightness, Contrast, Hue, Saturation, Sharpness, Gain) {Триггер выбора текущей регулировки уровня}
#define  WMBH_MUTE           WM_USER+213	//  Toggle Mute/UnMute {Триггер выключить-включить звук}
#define  WMBH_SETBRITN       WM_USER+214	//  Set Britness level   (LParam = 0..255) {Установить значение яркости}
#define  WMBH_SETCONTR       WM_USER+215	//  Set Contrast level   (LParam = 0..127) {Установить значение контрастности}
#define  WMBH_SETSAT         WM_USER+216	//  Set Saturation level (LParam = 0..127) {Установить значение насыщенности цвета}
#define  WMBH_SETHUE         WM_USER+217	//  Set Hue level        (LParam = -128..127) {Установить значение оттенка цвета}
#define  WMBH_SETSHR         WM_USER+218	//  Set Sharpness level  (LParam = -8..7) {Установить значение резкости}
#define  WMBH_SETGAIN        WM_USER+219	//  Set Video Gain level (LParam = 0..300) {Установить значение уровня видеоусиления}

#define  WMBH_CHANGESOURCE   WM_USER+220	//  Toggle modes (TV/FM/AV) {Триггер переключения режимов ПО}
#define  WMBH_CHANGETVFM     WM_USER+221	//  Toggle modes TV/FM {Триггер переключения режимов TV/FM}
#define  WMBH_CHANGETV       WM_USER+222	//  Select TV mode {Переключить в режим TV}
#define  WMBH_CHANGEFM       WM_USER+223	//  Select FM mode {Переключить в режим FM}
#define  WMBH_CHANGECVBS     WM_USER+224	//  Select AV-CVBS mode {Переключить в режим AV-CVBS}
#define  WMBH_CHANGESVID     WM_USER+225	//  Select AV-SVideo mode {Переключить в режим AV-SVideo}
// Compatible with version 5.00 and higher
#define  WMBH_CHANGEDVB      WM_USER+226	//  Toggle DVB/Analog modes {Триггер переключения режимов тюнера DVB/Analog}
// Compatible with version 5.00 and higher

#define  WMBH_FULLSCREEN     WM_USER+230	//  Toggle FullScreen/Window mode {Триггер переключения полноэкранного-оконного режима}
#define  WMBH_SETONTOP       WM_USER+231	//  Toggle On/Off main panel Stay-OnTop mode {Триггер переключения поверх всех окон для главной панели}
#define  WMBH_FREEZE         WM_USER+232	//  Toggle On/Off freeze frame {Триггер стоп-кадра}
#define  WMBH_SETONTOPVW     WM_USER+233	//  Toggle On/Off video window Stay-OnTop mode {Триггер переключения поверх всех окон для видеоокна}

#define  WMBH_TSSTART        WM_USER+234	//  Timeshift start {Запустить Таймшифт}
#define  WMBH_TSSTOP         WM_USER+235	//  Timeshift stop {Остановить Таймшифт}
#define  WMBH_TSPAUSE        WM_USER+236	//  Timeshift pause {Приостановить Таймшифт}
#define  WMBH_TSCONTINUE     WM_USER+237	//  Timeshift continue {Продолжить Таймшифт}
#define  WMBH_TSFORWARD      WM_USER+238	//  Timeshift step forward (LParam = step time in milliseconds, min. value = 5000) {Перемотка Таймшифт на шаг вперед}
#define  WMBH_TSBACKWARD     WM_USER+239	//  Timeshift step backward (LParam = step time in milliseconds, min. value = 5000) {Перемотка Таймшифт на шаг назад}

#define  WMBH_RESETVIDEO     WM_USER+240	//  Reset video amplifier volume to default {Сбросить параметры видеомикшера в значение по умолчанию}
#define  WMBH_SETA2CHNL      WM_USER+241	//  Change A2 CH1/CH2 or NICAM M1/M2 or BTSC SAP audio channels {Изменить режим вывода TV стереоканалов}
#define  WMBH_SETSLEEP       WM_USER+242	//  Set sleep timer {Установка таймера на выключение}

// Compatible with version 5.20 and higher
#define  WMBH_ZOOM_UP        WM_USER+244	//  Increase video zoom
#define  WMBH_ZOOM_DOWN      WM_USER+245	//  Decrease video zoom
#define  WMBH_ZOOM_VALUE     WM_USER+246	//  Set video zoom (LParam = zoom value in %, range -40..+50)
#define  WMBH_ASPECT_NEXT    WM_USER+248	//  Next video aspect ratio mode
#define  WMBH_ASPECT_VALUE   WM_USER+249	//  Set video aspect ratio mode (LParam = aspect mode, range 0..7) 
// Compatible with version 5.20 and higher

#define  WMBH_TELETEXT       WM_USER+250	//  Toggle On/Off teletext mode {Триггер включения-выключения режима телетекста}
#define  WMBH_SURFING        WM_USER+251	//  Toggle Start/Stop channels surfing mosaic {Триггер включения-выключения режима сёрфинга каналов}
#define  WMBH_TVGUIDEC       WM_USER+252	//  Show current TVGuide program {Показать текущую телепередачу в OSD}
#define  WMBH_TVGUIDEP       WM_USER+253	//  Show previous TVGuide program {Показать предыдущую телепередачу в OSD}
#define  WMBH_TVGUIDEN       WM_USER+254	//  Show next TVGuide program {Показать следующую телепередачу в OSD}

#define  WMBH_RECV           WM_USER+260	//  Toggle Start/Stop Video record {Триггер запустить-остановить видеозапись}
#define  WMBH_RECA           WM_USER+262	//  Toggle Start/Stop Audio record {Триггер запустить-остановить аудиозапись}
#define  WMBH_RECSNAP        WM_USER+263	//  Make snapshot {Сделать единичный снимок}
#define  WMBH_RECSNAPM       WM_USER+264	//  Toggle Start/Stop Multi-snapshot {Триггер запустить-остановить формирование серии снимков}
#define  WMBH_RECPAUSE       WM_USER+265	//  Toggle Pause/Continue any recording {Триггер пауза-продолжить запись}
#define  WMBH_RECLIMIT       WM_USER+266	//  Instant select record limit time {Быстрый выбор лимита времени записи}

#define  WMBH_RECVSTART      WM_USER+270	//  Start Video record {Запустить видеозапись}
#define  WMBH_RECVSTOP       WM_USER+271	//  Stop Video record {Остановить видеозапись}
#define  WMBH_RECASTART      WM_USER+274	//  Start Audio record {Запустить аудиозапись}
#define  WMBH_RECASTOP       WM_USER+275	//  Stop Audio record {Остановить аудиозапись}
#define  WMBH_RECMULTISTART  WM_USER+276	//  Start Multi-snapshot {Запустить формирование серии снимков}
#define  WMBH_RECMULTISTOP   WM_USER+277	//  Stop Multi-snapshot {Остановить формирование серии снимков}
#define  WMBH_RECPAUSEON     WM_USER+278	//  Set Pause for any recording {Установить паузу записи}
#define  WMBH_RECPAUSEOFF    WM_USER+279	//  Set Unpause for any recording {Снять паузу записи}

#define  WMBH_SETVOLUME      WM_USER+280	//  Set sound volume level (LParam = 0..65535) {Установить уровень громкости}
#define  WMBH_GETVOLUME      WM_USER+281	//  Get sound volume level (Result = 0..65535), use SendMessage {Получить текущий уровень громкости}
#define  WMBH_SETMUTE        WM_USER+282	//  Set global sound mute/unmute (Mute: LParam = 1, Unmute: LParam = 0) {Выключить/включить глобальный звук}

// Compatible with version 4.80 and higher
#define  WMBH_SETMUTESAFE    WM_USER+283	//  Set local sound mute/unmute (Mute: LParam = 1, Unmute: LParam = 0) {Выключить/включить локальный звук}
// Compatible with version 4.80 and higher

#define  WMBH_GETVERSION     WM_USER+285	//  Get version of Behold TV (see example), use SendMessage {Получить новер версии ПО}
// Compatible with version 5.22 and higher
#define  WMBH_GETPLOCK       WM_USER+286	//  Get analog video VSYNC status or DVB Lock status, use SendMessage {Получить статус наличия видеосигнала в аналоговом режиме или статус захвата мультиплекса в DVB режиме}
#define  WMBH_GETCHNLN       WM_USER+287	//  Get current absolute channel number, use SendMessage {Получить текущий порядковый номер канала}
// Compatible with version 5.22 and higher

#define  WMBH_SLEEPWAKE      WM_USER+290	//  Toggle sleep to tray/Wake up {Триггер свернуть ПО в системный трей-восстановить в нормальный режим}
#define  WMBH_EXIT           WM_USER+291	//  Exit program {Выйти из ПО}
#define  WMBH_SUSPEND        WM_USER+292	//  Suspend Windows {Перевести Windows в ждущий режим}
#define  WMBH_HIBERNATE      WM_USER+293	//  Hibernate Windows {Перевести Windows в режим Хибернейт (спящий режим)}
#define  WMBH_SHUTDOWN       WM_USER+294	//  Shutdown system {Выключить компютер}

// Compatible with version 5.10 and higher
#define  WMBH_SLEEP          WM_USER+295	//  Sleep to tray {Cвернуть ПО в системный трей}
#define  WMBH_WAKE           WM_USER+296	//  Wake up from tray {Восстановить ПО в нормальный режим из трея}
// Compatible with version 5.10 and higher


#endif
