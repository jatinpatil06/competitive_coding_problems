class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto outer_it = image.begin(); outer_it != image.end(); outer_it++)
        {
            reverse(outer_it -> begin(), outer_it -> end());
        }
        for(auto outer_it = image.begin(); outer_it != image.end(); outer_it++)
        {
            for(auto inner_it = outer_it -> begin(); inner_it != outer_it -> end(); inner_it++)
                *inner_it = (*inner_it + 1) % 2;
        }
        return image;
    }
};