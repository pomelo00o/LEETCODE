class Solution {
public:
    string convert(string s, int numRows) {
        const int Size = s.size();
        if ((Size <= numRows) || (numRows == 1))
        {
            return s;
        }
        const int Step = 2 * numRows - 2;
        string Result;
        for (int RowIndex = 0; RowIndex < numRows; RowIndex++)
        {
            int Index = RowIndex;
            if ((RowIndex == 0) || (RowIndex == (numRows - 1)))
            {
                while (Index < Size)
                {
                    Result.push_back(s[Index]);
                    Index = Index + Step;
                }
                continue;
            }
            int SecondIndex = Step - Index;
            while ((Index < Size) || (SecondIndex < Size))
            {
                if (Index < Size)
                {
                    Result.push_back(s[Index]);
                    Index = Index + Step;
                }
                if (SecondIndex < Size)
                {
                    Result.push_back(s[SecondIndex]);
                    SecondIndex = SecondIndex + Step;
                }
            }
        }
        return Result;
    }
};