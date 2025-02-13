#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }

static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
#if VANITYGAPS_PATCH
static const int smartgaps                 = 0;  /* 1 means no outer gap when there is only one window */
static const int monoclegaps               = 0;  /* 1 means outer gaps in monocle layout */
#endif // VANITYGAPS_PATCH
static const unsigned int borderpx         = 2;  /* border pixel of windows */
#if VANITYGAPS_PATCH
static const unsigned int gappih           = 20; /* horiz inner gap between windows */
static const unsigned int gappiv           = 20; /* vert inner gap between windows */
static const unsigned int gappoh           = 30; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov           = 30; /* vert outer gap between windows and screen edge */
#endif // VANITYGAPS_PATCH
static const float rootcolor[]             = COLOR(0x282a36ff);
static const float bordercolor[]           = COLOR(0x4d4d4dff);
static const float focuscolor[]            = COLOR(0xbd93f9ff);
static const float urgentcolor[]           = COLOR(0xff5555ff);
#if FLOAT_UNFOCUSED_BORDER_COLOR_PATCH
static const float floatcolor[]            = COLOR(0xff79c6ff);
#endif // FLOAT_UNFOCUSED_BORDER_COLOR_PATCH
/* This conforms to the xdg-protocol. Set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.1f, 0.1f, 0.1f, 1.0f}; /* You can also use glsl colors */

/* tagging - TAGCOUNT must be no greater than 31 */
#define TAGCOUNT (9)

static int log_level = WLR_ERROR;

#if MENU_PATCH
static const Menu menus[] = {
	/* command          feed function   action function */
	{ "rofi -dmenu -i", menuwinfeed,    menuwinaction    },
	{ "rofi -dmenu -i", menulayoutfeed, menulayoutaction },
};
#endif // MENU_PATCH

#if SETUPENV_PATCH
static const Env envs[] = {
	/* variable			value */
	{ "XDG_CURRENT_DESKTOP",	"wlroots" },
};
#endif // SETUPENV_PATCH

#if AUTOSTART_PATCH
static const char *const autostart[] = {
    "wbg", "/path/to/your/image", NULL,
    NULL /* terminate */
};
#endif // AUTOSTART_PATCH

static const Rule rules[] = {
	/* app_id                   title       tags mask     isfloating   monitor */
	{ "thunderbird-esr",        NULL,       1 << 0,       0,           -1 }, /* Start on ONLY tag "1" */
	{ "Beeper",                 NULL,       1 << 1,       0,           -1 }, /* Start on ONLY tag "2" */
	{ "zoom",                   NULL,       1 << 1,       0,           -1 }, /* Start on ONLY tag "2" */
	{ "Signal",                 NULL,       1 << 1,       0,           -1 }, /* Start on ONLY tag "2" */
	{ "discord",                NULL,       1 << 1,       0,           -1 }, /* Start on ONLY tag "2" */
	{ "obsidian",               NULL,       1 << 2,       0,           -1 }, /* Start on ONLY tag "3" */
	{ "pocket-casts-linux",     NULL,       1 << 3,       0,           -1 }, /* Start on ONLY tag "4" */
	{ "Spotify",                NULL,       1 << 3,       0,           -1 }, /* Start on ONLY tag "4" */
	{ "Vivaldi-stable",         NULL,       1 << 4,       0,           -1 }, /* Start on ONLY tag "5" */
	{ "foot",                   NULL,       1 << 5,       0,           -1 }, /* Start on ONLY tag "6" */
	{ "Emacs",                  NULL,       1 << 6,       0,           -1 }, /* Start on ONLY tag "7" */
	{ "steam",                  NULL,       1 << 7,       0,           -1 }, /* Start on ONLY tag "8" */
	{ "lutris",                 NULL,       1 << 7,       0,           -1 }, /* Start on ONLY tag "8" */
	{ "net.davidotek.pupgui2",  NULL,       1 << 7,       0,           -1 }, /* Start on ONLY tag "8" */
	{ "gamescope",              NULL,       1 << 7,       0,           -1 }, /* Start on ONLY tag "8" */
	{ "syncthing-gtk",          NULL,       1 << 8,       0,           -1 }, /* Start on ONLY tag "9" */
	{ "openrgb",                NULL,       1 << 8,       0,           -1 }, /* Start on ONLY tag "9" */
};

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
#if GAPLESSGRID_PATCH
	{ "###",      gaplessgrid },
#endif // GAPLESSGRID_PATCH
};

/* (x=-1, y=-1) is reserved as an "autoconfigure" monitor position indicator
 * WARNING: negative values other than (-1, -1) cause problems with Xwayland clients
 * https://gitlab.freedesktop.org/xorg/xserver/-/issues/899
*/
/* NOTE: ALWAYS add a fallback rule, even if you are completely sure it won't be used */
static const MonitorRule monrules[] = {
	/* name       mfact  nmaster scale layout       rotate/reflect                x    y */
	/* example of a HiDPI laptop monitor:
	{ "eDP-1",    0.5f,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	*/
	/* defaults */
	{ NULL,       0.5f, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
};

static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	/* example:
	.options = "ctrl:nocaps",
	*/
	.options = NULL,
};

#if NUMLOCK_CAPSLOCK_PATCH
/* numlock and capslock */
static const int numlock = 1;
static const int capslock = 0;
#endif // NUMLOCK_CAPSLOCK_PATCH

static const int repeat_rate = 25;
static const int repeat_delay = 600;

static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 1;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
#if UNCLUTTER_PATCH
static const int cursor_timeout = 5;
#endif // UNCLUTTER_PATCH

/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;

/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_LOGO

#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,SKEY,toggletag, {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *termcmd[]         = { "foot", NULL };
static const char *menucmd[]         = { "rofi", "-show", "combi", NULL };

static const Key keys[] = {
	/* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
	/* modifier                  key                 function        argument */
	{ MODKEY,                    XKB_KEY_p,          spawn,          {.v = menucmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Return,     spawn,          {.v = termcmd} },
#if IPC_PATCH
	{ MODKEY,                    XKB_KEY_b,          togglebar,      {0} },
#endif // IPC_PATCH
	{ MODKEY,                    XKB_KEY_j,          focusstack,     {.i = +1} },
	{ MODKEY,                    XKB_KEY_k,          focusstack,     {.i = -1} },
#if MOVESTACK_PATCH
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_J,          movestack,      {.i = +1} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_K,          movestack,      {.i = -1} },
#endif // MOVESTACK_PATCH
	{ MODKEY,                    XKB_KEY_i,          incnmaster,     {.i = +1} },
	{ MODKEY,                    XKB_KEY_d,          incnmaster,     {.i = -1} },
	{ MODKEY,                    XKB_KEY_h,          setmfact,       {.f = -0.05f} },
	{ MODKEY,                    XKB_KEY_l,          setmfact,       {.f = +0.05f} },
#if VANITYGAPS_PATCH
    { MODKEY|WLR_MODIFIER_ALT,   XKB_KEY_h,          incgaps,       {.i = +1 } },
    { MODKEY|WLR_MODIFIER_ALT,   XKB_KEY_l,          incgaps,       {.i = -1 } },
	{ MODKEY|WLR_MODIFIER_ALT|WLR_MODIFIER_SHIFT,   XKB_KEY_H,      incogaps,      {.i = +1 } },
	{ MODKEY|WLR_MODIFIER_ALT|WLR_MODIFIER_SHIFT,   XKB_KEY_L,      incogaps,      {.i = -1 } },
	{ MODKEY|WLR_MODIFIER_ALT|WLR_MODIFIER_CTRL,    XKB_KEY_h,      incigaps,      {.i = +1 } },
	{ MODKEY|WLR_MODIFIER_ALT|WLR_MODIFIER_CTRL,    XKB_KEY_l,      incigaps,      {.i = -1 } },
	{ MODKEY|WLR_MODIFIER_ALT,  XKB_KEY_0,          togglegaps,     {0} },
	{ MODKEY|WLR_MODIFIER_ALT|WLR_MODIFIER_SHIFT,   XKB_KEY_parenright,defaultgaps,    {0} },
	{ MODKEY,                    XKB_KEY_y,          incihgaps,     {.i = +1 } },
	{ MODKEY,                    XKB_KEY_o,          incihgaps,     {.i = -1 } },
	{ MODKEY|WLR_MODIFIER_CTRL,  XKB_KEY_y,          incivgaps,     {.i = +1 } },
	{ MODKEY|WLR_MODIFIER_CTRL,  XKB_KEY_o,          incivgaps,     {.i = -1 } },
	{ MODKEY|WLR_MODIFIER_ALT,   XKB_KEY_y,          incohgaps,     {.i = +1 } },
	{ MODKEY|WLR_MODIFIER_ALT,   XKB_KEY_o,          incohgaps,     {.i = -1 } },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Y,          incovgaps,     {.i = +1 } },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_O,          incovgaps,     {.i = -1 } },
#endif // VANITYGAPS_PATCH
	{ MODKEY,                    XKB_KEY_Return,     zoom,           {0} },
	{ MODKEY,                    XKB_KEY_Tab,        view,           {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_C,          killclient,     {0} },
	{ MODKEY,                    XKB_KEY_t,          setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                    XKB_KEY_f,          setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                    XKB_KEY_m,          setlayout,      {.v = &layouts[2]} },
#if GAPLESSGRID_PATCH
	{ MODKEY,                    XKB_KEY_g,          setlayout,      {.v = &layouts[3]} },
#endif // GAPLESSGRID_PATCH
	{ MODKEY,                    XKB_KEY_space,      setlayout,      {0} },
#if MENU_PATCH
	{ MODKEY|WLR_MODIFIER_SHIFT|WLR_MODIFIER_CTRL, XKB_KEY_p, menu,  {.v = &menus[0]} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_P,          menu,           {.v = &menus[1]} },
#endif // MENU_PATCH
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_space,      togglefloating, {0} },
	{ MODKEY,                    XKB_KEY_e,         togglefullscreen, {0} },
#if FAKE_FULLSCREEN_CLIENT_PATCH
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_E,          togglefakefullscreen, {0} },
#endif // FAKE_FULLSCREEN_CLIENT_PATCH
	{ MODKEY,                    XKB_KEY_0,          view,           {.ui = ~0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_parenright, tag,            {.ui = ~0} },
	{ MODKEY,                    XKB_KEY_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY,                    XKB_KEY_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_less,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_greater,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },
	TAGKEYS(          XKB_KEY_1, XKB_KEY_exclam,                     0),
	TAGKEYS(          XKB_KEY_2, XKB_KEY_at,                         1),
	TAGKEYS(          XKB_KEY_3, XKB_KEY_numbersign,                 2),
	TAGKEYS(          XKB_KEY_4, XKB_KEY_dollar,                     3),
	TAGKEYS(          XKB_KEY_5, XKB_KEY_percent,                    4),
	TAGKEYS(          XKB_KEY_6, XKB_KEY_asciicircum,                5),
	TAGKEYS(          XKB_KEY_7, XKB_KEY_ampersand,                  6),
	TAGKEYS(          XKB_KEY_8, XKB_KEY_asterisk,                   7),
	TAGKEYS(          XKB_KEY_9, XKB_KEY_parenleft,                  8),
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Q,          quit,           {0} },

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_Terminate_Server, quit, {0} },
	/* Ctrl-Alt-Fx is used to switch to another VT, if you don't know what a VT is
	 * do not remove them.
	 */
#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};
