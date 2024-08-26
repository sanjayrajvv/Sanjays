class FoodRatings {
private:
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, int> foodRatingMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            cuisineFoodMap[cuisines[i]].insert({-ratings[i], foods[i]});
            foodCuisineMap[foods[i]] =  cuisines[i];
            foodRatingMap[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisineMap[food];
        int rating = foodRatingMap[food];

        cuisineFoodMap[cuisine].erase({-rating, food});
        cuisineFoodMap[cuisine].insert({-newRating, food});

        foodRatingMap[food] = newRating;       
    }
    
    string highestRated(string cuisine) {
        auto& highestRated = cuisineFoodMap[cuisine];

        return highestRated.begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */