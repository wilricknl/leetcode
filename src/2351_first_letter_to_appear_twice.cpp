char repeatedCharacter(string s) {
	std::unordered_set<char> letters;
	for (char letter : s)
	{
		if (letters.contains(letter))
			return letter;
		letters.insert(letter);
	}
	return 'w';
}

