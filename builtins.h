#ifndef BUILTINS_H
#define BUILTINS_H

/*
 * prototypes
 */

int blt_in_ext(_mn *bii);
int blt_in_cd(_mn *bii);
int st_wk_dir(_mn *bii, char *new_dir);
int blt_in_hlp(_mn *bii);
int blt_in_alias(_mn *bii);
int blt_in_env(_mn *bii);
int blt_set_env(_mn *bii);
int blt_in_unset_ev(_mn *bii);
int blt_in_lst(_mn *bii);

#endif 
