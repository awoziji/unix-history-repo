/* Copyright (c) 1982 Regents of the University of California */

static char sccsid[] = "@(#)ASRTS.c 1.1 %G%";

char EASRTS[] = "Assertion failed: %s\n";

ASRTS(cond, stmt)
	short	cond;
	char	*stmt;
{
	if (cond)
		return;
	ERROR(EASRTS, stmt);
	return;
}
