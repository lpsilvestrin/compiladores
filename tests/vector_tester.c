int vec1[3]: 1 1 1;
float vec2[3];
char vec3[3];
int i = 0;

int increment(int value) {
	return value +1;
}

int main () {
	vec1[1] = 2;
	vec1[0] = 3;
	vec1[2] = 3;
	print vec1[2];
	//vec2[0] = 3.4;
	//vec3[0] = 'm';
	//print vec1[0] vec2[0] vec3[0];
	//while(i < 3) {print vec1[i] "\n"; i = increment(i);}
}
