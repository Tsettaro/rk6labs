high ([1-9][0-9]?|1([01][0-9]|2[0-6]))
low ([01]?[0-9][0-9]?|2[0-4][0-9]|25[0-5])

%%
{high}(\.{low}){3} ECHO; putchar('\n');
[^\ \n\t]*[1-9\.]+[^\ \n\t]* ;
.|\n ;