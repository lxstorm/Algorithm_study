static int SizeDirectory(DirectoryOrFile D)
{
	int TotalSize;

	TotalSize = 0;
	if (D is a legitimate entry)
	{
		TotalSize = FileSize(D);
		if (D is a directory)
			for each child C of D
				TotalSize = SizeDirctory(C);
	}
	return TotalSize;
}