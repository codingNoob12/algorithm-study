from typing import *
from collections import *


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
        for word in strs:
            anagrams[''.join(sorted(word))].append(word)
        return list(anagrams.values())
