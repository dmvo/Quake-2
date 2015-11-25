// sys_null.h -- null system driver to aid porting efforts

#include "../qcommon/qcommon.h"
#include "errno.h"
#include <dlfcn.h>
#include <limits.h>

int	curtime;

unsigned	sys_frame_time;

qboolean stdin_active = true;

void Sys_mkdir (char *path)
{
}

void Sys_Error (char *error, ...)
{
	va_list		argptr;

	printf ("Sys_Error: ");	
	va_start (argptr,error);
	vprintf (error,argptr);
	va_end (argptr);
	printf ("\n");

	exit (1);
}

void Sys_Quit (void)
{
	exit (0);
}

static void *game_library;

void	Sys_UnloadGame (void)
{
	if (game_library)
		dlclose(game_library);

	game_library = NULL;
}

void	*Sys_GetGameAPI (void *parms)
{
	char *path = NULL;
	char curpath[PATH_MAX];
	char name[PATH_MAX];
	const char gamename[] = "game.so";
	void *(*GetGameAPI)(void *);

	getcwd(curpath, sizeof(curpath));

	while (1) {
		path = FS_NextPath(path);
		if (!path)
			return NULL;

		sprintf(name, "%s/%s/%s", curpath, path, gamename);

		game_library = dlopen(name, RTLD_NOW);
		if (game_library)
			break;
	}

	GetGameAPI = (void *)dlsym(game_library, "GetGameAPI");

	if (!GetGameAPI) {
		Sys_UnloadGame();
		return NULL;
	}

	return GetGameAPI(parms);
}

char *Sys_ConsoleInput (void)
{
	return NULL;
}

void	Sys_ConsoleOutput (char *string)
{
}

void Sys_SendKeyEvents (void)
{
}

void Sys_AppActivate (void)
{
}

void Sys_CopyProtect (void)
{
}

char *Sys_GetClipboardData( void )
{
	return NULL;
}

static byte *membase;
static int maxhunksize, curhunksize;

void *Hunk_Begin (int maxsize)
{
	membase = malloc(maxsize);

	if (!membase)
		Sys_Error(ERR_FATAL, "unable to allocate %d bytes", maxsize);

	maxhunksize = maxsize;
	curhunksize = 0;

	return membase;
}

void *Hunk_Alloc (int size)
{
	byte *buf;

	if (curhunksize + size > maxhunksize)
		Sys_Error(ERR_FATAL, "Hunk_Alloc overflow");

	buf = membase + curhunksize;
	curhunksize += size;

	return buf;
}

void Hunk_Free (void *buf)
{
	if (buf)
		free(buf);
}

int Hunk_End (void)
{
	byte *n = realloc(membase, curhunksize);

	if (n != membase)
		Sys_Error(ERR_FATAL, "Couldn't remap block (%d)", errno);

	return curhunksize;
}

int		Sys_Milliseconds (void)
{
	return 0;
}

void	Sys_Mkdir (char *path)
{
}

char	*Sys_FindFirst (char *path, unsigned musthave, unsigned canthave)
{
	return NULL;
}

char	*Sys_FindNext (unsigned musthave, unsigned canthave)
{
	return NULL;
}

void	Sys_FindClose (void)
{
}

void	Sys_Init (void)
{
}


//=============================================================================

void main (int argc, char **argv)
{
	Qcommon_Init (argc, argv);

	while (1)
	{
		Qcommon_Frame (0.1);
	}
}


