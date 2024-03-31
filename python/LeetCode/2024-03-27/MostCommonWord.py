import re
from collections import Counter
from typing import *


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = paragraph.lower()
        paragraph = re.sub('[!?\',;.]', ' ', paragraph)
        not_banned_words = list(filter(lambda x: x not in banned, paragraph.split()))
        words_counter = Counter(not_banned_words)
        return words_counter.most_common(1)[0][0]
