/* $Id$ */
/* Copyright (c) 2005-2014 Pierre Pronchery <khorben@defora.org> */
/* This file is part of DeforaOS Unix sh */
/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. */



#ifndef SH_JOB_H
# define SH_JOB_H


/* types */
typedef enum _JobStatus { JS_RUNNING, JS_WAIT } JobStatus;


/* functions */
int job_add(char * command, pid_t pid, JobStatus status);
int job_kill_status(int signum, JobStatus status);
/* TODO
switch to job X
send job Y to background */
int job_list(int argc, char * argv[]);
int job_pgids(int argc, char * argv[]);
int job_status(int argc, char * argv[]);

#endif /* SH_JOB_H */
