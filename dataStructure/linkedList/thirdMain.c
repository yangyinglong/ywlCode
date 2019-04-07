void PrintName();
void PrintLoves();
void PrintSomething();
void DoSomething();

int main()
{
	PrintName();
	DoSomething();
	return 0;
}

void DoSomething()
{
	PrintLoves();
	PrintSomething();
}