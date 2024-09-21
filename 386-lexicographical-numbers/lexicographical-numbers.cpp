class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicNumbers;

        for (int start = 1; start <= 9; start++) {
            generateLexicalNumbers(start, n, lexicographicNumbers);
        }

        return lexicographicNumbers;
    }

private:
    void generateLexicalNumbers(int currentNumber, int limit, 
                        vector<int>& lexicographicNumbers) {
        if (currentNumber > limit) {
            return;
        }

        lexicographicNumbers.push_back(currentNumber);

        for (char nextDigit = 0; nextDigit <= 9; ++nextDigit) {
            int nextNumber = currentNumber * 10 + nextDigit;

            if (nextNumber <= limit){
                generateLexicalNumbers(nextNumber, limit, lexicographicNumbers);
            } else {
                break;
            }
        }
    }
};