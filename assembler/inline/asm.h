inline int ReadTSC()
{
	asm(
		"rdtsc");
}
