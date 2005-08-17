/* job.c */



#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "sh.h"
#include "job.h"


/* types */
typedef struct _Job
{
	char * command;
	pid_t pid;
	JobStatus status;
	int error;
} Job;


/* variables */
static Job * jobs = NULL;
static unsigned int jobs_cnt = 0;


/* job_add */
static int _add_wait(unsigned int id);
static void _add_wait_all(void);
int job_add(char * command, pid_t pid, JobStatus status)
{
	Job * p;
	int ret = 0;

#ifdef DEBUG
	fprintf(stderr, "%s%u%s", "job_add(", jobs_cnt+1, ")\n");
#endif
	if((command = strdup(command)) == NULL)
		return sh_error("malloc", 1);
	if((p = realloc(jobs, sizeof(Job) * (jobs_cnt+1))) == NULL)
	{
		free(command);
		return sh_error("malloc", 1);
	}
	jobs = p;
	jobs[jobs_cnt].command = command;
	jobs[jobs_cnt].pid = pid;
	jobs[jobs_cnt].status = status;
	jobs_cnt++;
	/* FIXME depending on further C-z handling we could do this earlier */
	if(status == JS_WAIT)
		ret = _add_wait(jobs_cnt);
	_add_wait_all();
	return ret;
}

static int _job_remove(unsigned int id);
static int _add_wait(unsigned int id)
{
	int status;
	int ret;

	while((ret = waitpid(jobs[id-1].pid, &status, 0)) != -1)
		if(WIFEXITED(status))
			break;
	if(ret == -1)
		return sh_error("waitpid", -1);
	_job_remove(id);
	return WEXITSTATUS(status);
}

static void _job_print(unsigned int id, char c, char * state);
static void _add_wait_all(void)
{
	pid_t pid = 0;
	int status;
	unsigned int i;

	while(jobs_cnt > 0 && (pid = waitpid(-1, &status, WNOHANG)) > 0)
	{
		for(i = 0; i < jobs_cnt && jobs[i].pid != pid; i++);
		if(i == jobs_cnt)
			continue;
		_job_print(i+1, 'X', "FIXME");
		_job_remove(i+1);
	}
	if(pid == -1)
		sh_error("waitpid", 0);
}


/* job_remove */
static int _job_remove(unsigned int id)
{
	Job * p;

#ifdef DEBUG
	fprintf(stderr, "%s%u%s", "job_remove(", id, ")\n");
#endif
	if(id > jobs_cnt)
		return 1;
	if(id > 1)
	{
		free(jobs[id-1].command);
		memmove(&jobs[id-1], &jobs[id], (jobs_cnt-id) * sizeof(Job));
		if((p = realloc(jobs, sizeof(Job) * (jobs_cnt-1))) == NULL)
			return sh_error("malloc", 1);
		jobs = p;
	}
	jobs_cnt--;
	return 0;
}


/* job_list */
int job_list(int argc, char * argv[])
{
	unsigned int i;
	int j;
	unsigned int id;
	char * p;

	if(argc == 0)
	{
		for(i = 0; i < jobs_cnt; i++)
			_job_print(i+1, 'X', "FIXME");
		return 0;
	}
	for(j = 1; j < argc; j++)
	{
		id = strtol(argv[j], &p, 10);
		if(*(argv[j]) == '\0' || *p != '\0' || id < 1 || id >= jobs_cnt)
			continue;
		_job_print(i+1, 'X', "FIXME");
	}
	return 0;
}


/* job_pgids */
int job_pgids(int argc, char * argv[])
{
	/* FIXME */
	return 1;
}


/* job_print */
static void _job_print(unsigned int id, char c, char * state)
{
	printf("[%u] %c %s %s\n", id, c, state, jobs[id-1].command);
}


/* job_status */
int job_status(int argc, char * argv[])
{
	/* FIXME */
	job_list(1, NULL);
	return 1;
}