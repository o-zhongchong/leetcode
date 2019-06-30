class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ordered_deck(deck);
        sort( ordered_deck.begin(), ordered_deck.end() );
        
        deque<int> dq;
        for( int i = ordered_deck.size() -1; i>=0; --i )
        {
            if( !dq.empty() )
            {
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
            }
            dq.push_front(ordered_deck[i]);
        }
        
        ordered_deck.assign(dq.begin(), dq.end());
        return ordered_deck;
    }
};