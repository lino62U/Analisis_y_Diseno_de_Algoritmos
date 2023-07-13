#include <iostream>
#include <vector>
#include <algorithm>

struct Segment {
    int start;
    int end;
};

bool cmp(Segment a, Segment b) {
    if (a.start < b.start)
        return true;
    return false;
}

int main() {
    int M;

    while (std::cin >> M) {
        int testcase = M;
        int temp, left, right;
        Segment input;
        std::vector<Segment> lines, answer;

        for (int i = 0; i < testcase; i++) {
            if (i)
                std::cout << "\n";

            std::cin >> M;

            lines.clear();
            while (std::cin >> input.start >> input.end && (input.start != 0 || input.end != 0))
                lines.push_back(input);

            std::sort(lines.begin(), lines.end(), cmp);

            answer.clear();
            left = 0;
            right = 0;
            for (int i = 0; i < lines.size(); i++) {
                temp = -1;
                for (; i < lines.size() && lines[i].start <= left; i++)
                    if (lines[i].end > right) {
                        right = lines[i].end;
                        temp = i;
                    }

                if (temp == -1)
                    break;
                answer.push_back(lines[temp]);
                if (right >= M)
                    break;
                left = right;
                i--;
            }

            if (right < M) {
                std::cout << "0\n";
                continue;
            }
            std::cout << answer.size() << "\n";
            for (int i = 0; i < answer.size(); i++)
                std::cout << answer[i].start << " " << answer[i].end << "\n";
        }
    }

    return 0;
}
