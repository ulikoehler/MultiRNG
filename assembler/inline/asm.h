int ReadTSC()
{
	asm(
		"rdtsc");
}