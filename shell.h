//
// Created by bzane on 2/10/2019.
//
#include <stdbool.h>

#ifndef TECHSHELL_SHELL_H
#define TECHSHELL_SHELL_H

//Initial DEFINE values for OS detection
#define GET_WINDOWS_HOMEPATH 0
#define GET_LINUX_HOMEPATH 0

//For any version of windows, including Cygwin dev environments
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#undef GET_WINDOWS_HOMEPATH
#define GET_WINDOWS_HOMEPATH 1
#endif //_WIN32

//For any version of *nix
#if defined(unix) || defined(__unix__) || defined (__unix)
#undef GET_UNIX_HOMEPATH
#define GET_UNIX_HOMEPATH 1
#endif //unix/__unix__/__unix

void enter_shell(void);
void parse_cl(char[], char*[], bool*, char**);
void execcmd(char**, const bool, const char*);

//Useful macros
#define command_compare(s) strcmp(command[0], s->cmd_str) == 0
#define call(cmd) (cmd->function)((const char**) command);
#define chk_builtin(command) if (command_compare(command)) { call(command); return; }
#define chk_builtins() chk_builtin(p_wd); chk_builtin(cd); chk_builtin(exit_cmd);
#define cmp_redir(redirect, s) strcmp(redirect, s) == 0
#define is_redirect(s) cmp_redir(">>", s) || cmp_redir("<<", s) || cmp_redir("2>", s)

#define db_printf(s) if (DEBUG) { printf("%s\n", s); }

//DEBUG macro for this file
#define DEBUG 1

#endif //TECHSHELL_SHELL_H
