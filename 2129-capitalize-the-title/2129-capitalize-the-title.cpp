class Solution {
public:
    string capitalizeTitle(string title) {
        int len = title.length();
		for(int i = 0; i < len; ++i) {
			int firstIndex = i;
			while(i < len && title[i]  != ' ') {
				title[i] |= 32;
				++i;
			}
			if(i - firstIndex > 2) {
				title[firstIndex] &= ~32;
			}
		}
		return title;
    }
};