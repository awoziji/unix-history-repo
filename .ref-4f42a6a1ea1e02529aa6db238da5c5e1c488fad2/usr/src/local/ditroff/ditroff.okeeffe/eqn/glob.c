#ifndef lint
static char sccsid[] = "@(#)glob.c	2.1 (CWI) 85/07/18";
#endif lint
#include "e.h"

int	dbg;		/* debugging print if non-zero */
int	lp[200];		/* stack for things like piles and matrices */
int	ct;		/* pointer to lp */
int	used[100];	/* available registers */
int	ps;		/* default init point size */
int	deltaps	= 3;	/* default change in ps */
int	gsize	= 10;	/* default initial point size */
int	ft	= '2';
Font	ftstack[10] = { '2', "2" };	/* bottom is global font */
Font	*ftp	= ftstack;
int	szstack[10];	/* non-zero if absolute size set at this level */
int	nszstack = 0;
int	display	= 0;	/* 1=>display, 0=>.EQ/.EN */

#ifdef	APS
	char	*typesetter = "aps";	/* name for -T */
	int	ttype	= DEVAPS;	/* type of typesetter today */
	int	res	= 723;		/* resolution of typesetter; dflt = 202 */
	int	minsize	= 5;		/* min size it can handle; ditto */
#else
	char	*typesetter = "har";
	int	ttype	= DEVHAR;	/* type of typesetter today */
	int	res	= 1445;		/* resolution of typesetter; dflt = har */
	int	minsize	= 4;		/* min size it can handle; ditto */
#endif
/*
 *	char	*typesetter = "202";
 *	int	ttype	= DEV202;	/* type of typesetter today
 *	int	res	= 972;		/* resolution of typesetter; dflt = 202
 *	int	minsize	= 5;		/* min size it can handle; ditto
*/

int	synerr;		/* 1 if syntax err in this eqn */
float	eht[100];
float	ebase[100];
int	eps[100];
int	lfont[100];
int	rfont[100];
int	eqnreg;		/* register where final string appears */
float	eqnht;		/* final height of equation */
int	lefteq	= '\0';	/* left in-line delimiter */
int	righteq	= '\0';	/* right in-line delimiter */
int	markline = 0;	/* 1 if this EQ/EN contains mark; 2 if lineup */
