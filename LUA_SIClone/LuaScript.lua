--
colour = 100
level = 10
lives = 10
playerSprite = "assets/Ufoph.bmp"

startpos = {x=0, y=0}
startpos.x = 500
startpos.y = 650

-- My own variables

lifeGain = 2
settleTheScore = 10000

--mothership chance
--laser chance
--level number
--level colour

math.randomseed(os.time())

function randomNumber()
	return math.random(1,10000)
end

function right( x, currentFrame )
	x = x+5
	if(x <= -5)
	then	
		x = -5
	end
	if(currentFrame > 1.9)
	then
		currentFrame = 0
	end
	return x,currentFrame
end

function left( x, currentFrame )
	x = x-5
	if(x >= 910)
	then	
		x = 910
	end
	if(currentFrame > 1.9)
	then
		currentFrame = 0
	end
	return x,currentFrame
end

function callMessage()
	display_message("Get a life", lifeGain)
end

function setPlayerScore()
	CDispatcher("setScore", settleTheScore)
end
