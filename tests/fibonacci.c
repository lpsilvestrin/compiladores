int n = 0;
int first = 0;
int second = 1;
int next = 0;
int c = 0;

int main()
{

  print "Enter the number of terms\n";
  read n;
 
  print "First " n " terms of Fibonacci series are:\n";
 
  while(c < n)
  {
    if (c <= 1) then {next = c;} else {next = first + second; first = second; second = next; };
    print next "\n";
   c = c + 1;
  }

}
