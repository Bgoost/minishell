# minishell
#### A (somewhat) simple bash emulator
Known Bugs with examples:
- `"*"hola`   Wildcard may expand when it should not
- `<< "'$USER'"` Ends with `''$USER'` instead of `'$USER'`
- `<< eof << eof3 | | << eof4` Here-docs before syntax error are not executed

By [anovoa](https://github.com/annoga) and yours truly
