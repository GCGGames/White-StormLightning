print( "Initializing 'SpaceShip' object." )
singleton:AddSprite( 0, false )
singleton:AddScanArea()
position:SetY( 300 )
position:SetX( math.random( 400 ) )
position:SetZ( 2 )
stack:AddInt( "a", 0, false )
sprite:SetRenderLayer( "levelRenderLayer0" )
stack:SetInt( "add", object:GetID() )
r = scanArea:GetR()
r.w = 64
r.h = 64
r.x = position:GetX() + 1
r.y = position:GetY() + 1
scanArea:SetR( r )
print( "Finished initializing 'SpaceShip' object." )
