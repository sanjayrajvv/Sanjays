struct Node {
    Node *links[2];

    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    Node *get(int bit) {
        return links[bit];
    }

    void put(int bit, Node *node) {
        links[bit] = node;
    }
};

class Trie {
    Node *root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node *node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int x) {
        //1) Take the 32nd bit and check if the current node
        //contains it's complement:
		  //If complement present:
				  //set 32nd bit 
			//else leave it
		//get next node
		//do it for all

        Node *node = root;
        int maxResult = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;

            int complement = 1 - bit;
            if (node->containsKey(complement)) {
                maxResult = maxResult | (1 << i);

                node = node->get(complement);
            } else {
                node = node->get(bit);
            }
        }

        return maxResult;
    }
};

class Solution {
    int maxXOR(vector<int> &arr1) {
        Trie trie;

        for (auto &it : arr1) {
            trie.insert(it);
        }

        int maxi = 0;
        for (auto &it : arr1) {
            maxi = max(maxi, trie.getMax(it));
        }

        return maxi;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        return maxXOR(nums);
    }
};