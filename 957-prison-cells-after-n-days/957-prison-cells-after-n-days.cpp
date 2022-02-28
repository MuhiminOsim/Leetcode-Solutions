class Solution {
public:
    void getNextState(vector<int>& cells) {
        vector<int> newCells((int)cells.size(), 0);
        
        for(int i = 1; i + 1 < cells.size(); i++) {
            newCells[i] = cells[i - 1] == cells[i + 1];
        }
        
        cells = newCells;
    }
    
    int getMask(vector<int>& cells) {
        int mask = 0;
        
        for(int i = 0; i < cells.size(); i++) {
            if(cells[i]) mask += (1 << i);
        }
        
        return mask;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<vector<int>> states;
        vector<int> seen(256, 0);
        
        while(!seen[getMask(cells)]) {
            seen[getMask(cells)] = states.size() + 1;
            states.push_back(cells);
            getNextState(cells);
        }
        
        int before = seen[getMask(cells)];
        n -= before - 1;
        int periodSize = states.size() - before + 1;
        int targetState = n % periodSize;
        
        return states[before - 1 + targetState];
    }
};