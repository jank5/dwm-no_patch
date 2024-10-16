/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 2;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrains Mono:size=18" };
static const char dmenufont[]       = "JetBrains Mono:size=18";

static const char col_gray1[]            = "#222222";
static const char col_gray2[]            = "#444444";
static const char col_gray3[]            = "#bbbbbb";
static const char col_gray4[]            = "#eeeeee";
static const char col_bg[]               = "#282a36";
static const char col_fg[]               = "#f8f8f2";
static const char col_comment[]          = "#6272a4";
static const char col_cyan[]             = "#8be9fd";
static const char col_green[]            = "#50fa7b";
static const char col_orange[]           = "#ffb86c";
static const char col_pink[]             = "#ff79c6";
static const char col_purple[]           = "#bd93f9";
static const char col_red[]              = "#ff5555";
static const char col_yellow[]           = "#f1fa8c";
static const char *colors[][3]           = {
	/*                 fg         bg         border   */
	[SchemeNorm] = { col_fg,    col_bg,     col_green },
	[SchemeSel]  = { col_fg,    col_purple, col_yellow },
};
/*
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	               fg         bg         border   
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
}; */

/* tagging */
static const char *tags[] = { "dev", "web", "fil", "vir", "edi", "soc", "aud", "gam", "oth", "0", "-", "=" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "obsidian", NULL,       NULL,       1 << 0,       0,           -1 },
	{ "floorp",   NULL,       NULL,       1 << 1,       0,           -1 },
	{ "firefox",  NULL,       NULL,       1 << 2,       0,           -1 },
	{ "waterfox", NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Rhythmbox",NULL,       NULL,       1 << 4,       0,           -1 },
	{ "TelegramDesktop",NULL, NULL,       1 << 1,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[tile]",      tile },    /* first entry is default */
	{ "[float]", NULL },    /* no layout function means floating behavior */
	{ "[Monocle]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] 						= { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  						= { "alacritty", NULL };
static const char *screenshot[] 					= { "flameshot", "gui", NULL };
static const char *shutdown[]             = { "shutdown", "now" , NULL };
static const char *reboot[]               = { "reboot", NULL };
static const char *emacs[]  							= {"emacs", NULL};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	//Add my hotkey
	{ MODKEY|ShiftMask,             XK_t,      spawn,          SHCMD("telegram-desktop") },
	{ MODKEY,                       XK_a,      spawn,          SHCMD("/home/zemo/.config/rofi/launchers/type-5/launcher.sh") },
	{ 0,                            XK_KP_Down,spawn,          SHCMD("pkill dwm") },
	{ 0,                            XK_F1,     spawn,          SHCMD("rhythmbox") },
	{ 0,                            XK_F2,     spawn,          SHCMD("brave") },
	{ MODKEY|ShiftMask,             XK_o,      spawn,          SHCMD("obsidian")  },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("floorp") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("waterfox") },
  { MODKEY|ShiftMask,             XK_q,      spawn,          SHCMD("firefox") },
  { MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD("vesktop") },
	{ MODKEY|ShiftMask,             XK_a,      spawn,          SHCMD("pavucontrol") },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ 0,                            XK_Print,  spawn,          {.v = screenshot } },
	{ MODKEY|ShiftMask,             XK_F9,     spawn,          {.v = shutdown } },
	{ MODKEY|ShiftMask,             XK_F8,     spawn,          {.v = reboot } },
	{ MODKEY,                       XK_e,      spawn,          {.v = emacs } },

	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	// { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	// { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                      9)
	TAGKEYS(                        XK_minus,                  10)
	TAGKEYS(                        XK_equal,                  11)
	{ MODKEY|ShiftMask,             XK_x,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

