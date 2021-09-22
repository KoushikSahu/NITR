%{
	#include <stdio.h>

	int ptr = -1;
	char ans[1000001];
%}

%%
ONE[ ] {
	ans[++ptr] = '1';
}
 
TWO[ ] {
	ans[++ptr] = '2';
} 

THREE[ ] {
	ans[++ptr] = '3';
}
 
FOUR[ ] {
	ans[++ptr] = '4';
} 
 
FIVE[ ] {
	ans[++ptr] = '5';
}
 
SIX[ ] {
	ans[++ptr] = '6';
}
 
SEVEN[ ] {
	ans[++ptr] = '7';
} 
 
EIGHT[ ] {
	ans[++ptr] = '8';
}
 
NINE[ ] {
	ans[++ptr] = '9';
} 

ONE[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '\0';
	return 1;
}
 
TWO[\n] {
	ans[++ptr] = '2';
	ans[++ptr] = '\0';
	return 1;
} 

THREE[\n] {
	ans[++ptr] = '3';
	ans[++ptr] = '\0';
	return 1;
}
 
FOUR[\n] {
	ans[++ptr] = '4';
	ans[++ptr] = '\0';
	return 1;
} 
 
FIVE[\n] {
	ans[++ptr] = '5';
	ans[++ptr] = '\0';
	return 1;
}
 
SIX[\n] {
	ans[++ptr] = '6';
	ans[++ptr] = '\0';
	return 1;
}
 
SEVEN[\n] {
	ans[++ptr] = '7';
	ans[++ptr] = '\0';
	return 1;
} 
 
EIGHT[\n] {
	ans[++ptr] = '8';
	ans[++ptr] = '\0';
	return 1;
}
 
NINE[\n] {
	ans[++ptr] = '9';
	ans[++ptr] = '\0';
	return 1;
} 
 
TEN[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '0';
}
 
ELEVEN[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '1';
	ans[++ptr] = '\0';
	return 1;
}
 
TWELVE[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '2';
	ans[++ptr] = '\0';
	return 1;
}

THIRTEEN[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '3';
	ans[++ptr] = '\0';
	return 1;
}
 
FORTEEN[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '4';
	ans[++ptr] = '\0';
	return 1;
}

FIFTEEN[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '5';
	ans[++ptr] = '\0';
	return 1;
}

SIXTEEN[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '6';
	ans[++ptr] = '\0';
	return 1;
}

SEVENTEEN[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '7';
	ans[++ptr] = '\0';
	return 1;
}
 
EIGHTEEN[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '8';
	ans[++ptr] = '\0';
	return 1;
}
 
NINETEEN[\n] {
	ans[++ptr] = '1';
	ans[++ptr] = '9';
	ans[++ptr] = '\0';
	return 1;
}

TWENTY[ ] {
	ans[++ptr] = '2';
}

TWENTY[\n] {
	ans[++ptr] = '2';
	ans[++ptr] = '0';
	ans[++ptr] = '\0';
	return 1;
}

THIRTY[ ] {
	ans[++ptr] = '3';
}

THIRTY[\n] {
	ans[++ptr] = '3';
	ans[++ptr] = '0';
	ans[++ptr] = '\0';
	return 1;
}

FOURTY[ ] {
	ans[++ptr] = '4';
}

FOURTY[\n] {
	ans[++ptr] = '4';
	ans[++ptr] = '0';
	ans[++ptr] = '\0';
	return 1;
}
 
FIFTY[ ] {
	ans[++ptr] = '5';
}

FIFTY[\n] {
	ans[++ptr] = '5';
	ans[++ptr] = '0';
	ans[++ptr] = '\0';
	return 1;
}

SIXTY[ ] {
	ans[++ptr] = '6';
} 

SIXTY[\n] {
	ans[++ptr] = '6';
	ans[++ptr] = '0';
	ans[++ptr] = '\0';
	return 1;
} 

SEVENTY[ ] {
	ans[++ptr] = '7';
} 

SEVENTY[\n] {
	ans[++ptr] = '7';
	ans[++ptr] = '0';
	ans[++ptr] = '\0';
	return 1;
} 

EIGHTY[ ] {	
	ans[++ptr] = '8';
} 

EIGHTY[\n] {
	ans[++ptr] = '8';
	ans[++ptr] = '0';
	ans[++ptr] = '\0';
	return 1;
} 

NINETY[ ] {
	ans[++ptr] = '9';
} 

NINETY[\n] {
	ans[++ptr] = '9';
	ans[++ptr] = '0';
	ans[++ptr] = '\0';
	return 1;
}

HUNDRED[ ] ;

AND[ ] ;

\n {
	ans[++ptr] = '\0';
	return 1;
}
%%

int yywrap(){
}

int main(){
    yylex();
    printf("%s\n", ans);
    return 0;
}