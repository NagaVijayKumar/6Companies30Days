class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        /*
  queue<pair<int,int>>rotten;
        int r = grid.size(),c = grid[0].size(),fresh = 0, time = 0;
        for(int i=0; i<r; i++){
        	for(int j=0; j<c; j++){
        		if(grid[i][j]==2){           //If orange is rotten push it Queue
        			rotten.push({i,j});
				}else if(grid[i][j]==1){     //If Orange is Fresh, count the fresh oranges
					fresh++;
				}
			}
		}
		
		while(!rotten.empty()){
			int num = rotten.size();
			for(int i=0; i<num; i++){
				int x = rotten.front().first, y = rotten.front().second;
				rotten.pop();
				if(x>0 && grid[x-1][y]==1){       //Top side  is fresh orange
					grid[x-1][y]=2;               // Rot the fresh orange
					fresh--;                      //Decreament the count of fresh oranges
					rotten.push({x-1,y});            // add the newly rotten orange to queue
				}
				if(x<r-1 && grid[x+1][y]==1){		  // Down
					grid[x+1][y] = 2;
					fresh--;
					rotten.push({x+1,y});
				}
				
				if(y<c-1 && grid[x][y+1]==1){        //right
					grid[x][y+1] = 2;
					fresh--;
					rotten.push({x,y+1});
				}
				if(y>0 && grid[x][y-1]==1){          // Left
					grid[x][y-1]=2;
					fresh--;
					rotten.push({x,y-1});
				}
			}
			if(!rotten.empty()){              //If queue is not empty, then we increase the time frame
				time++;
			}
		}
		
		if(fresh==0){
			return time;
		}return -1;      
        
        */
        
        
        
      
        
        // push all the rottern oranges into queue,
        // do bfs on those
        
        int r = grid.size(), c = grid[0].size(), time = 0, fresh = 0;
        
        queue<pair<int,int>>rotten;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1){             // If orange is fresh, increase fresh count
                    fresh++;
                }
                if(grid[i][j]==2){             // If orange is rotten, push into queue
                    rotten.push({i,j});
                }
            }
        }
        
     
        while(!rotten.empty()){
            int num = rotten.size();
            
            while(num--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                
                //Top
                if(x>0 && grid[x-1][y]==1){
                    fresh--;                  // Decrease the fresh count
                    grid[x-1][y] = 2;         // Rot the Orange
                    rotten.push({x-1,y});     // push into queue
                }

                //Down
                if(x<r-1 && grid[x+1][y]==1){
                    fresh--;
                    grid[x+1][y] = 2;
                    rotten.push({x+1,y});
                }
 
                //Right
                if(y<c-1 && grid[x][y+1]==1){
                    fresh--;
                    grid[x][y+1] = 2;
                    rotten.push({x,y+1});
                }

                //Left
                if(y>0 && grid[x][y-1]==1){
                    fresh--;
                    grid[x][y-1] = 2;
                    rotten.push({x,y-1});
                }
                
            }
                            
            if(!rotten.empty()){
                time++;
            }

        }
        
        if(fresh==0){
            return time;
        }
        return -1;
        
        
    }
};
