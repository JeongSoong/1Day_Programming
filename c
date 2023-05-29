clc;
clear;

players = ["P", "C"];  % 플레이어 이름 배열

totalSticks = 31;  % 총 막대 개수
maxPick = 3;  % 최대로 가져갈 수 있는 막대 개수

currentPlayer = 1;  % 현재 플레이어 인덱스

while totalSticks > 0
    fprintf('Left Sticks: %d\n', totalSticks);
    fprintf('%s\n', players(currentPlayer));

    % 플레이어가 막대 개수를 입력하도록 함
    if currentPlayer == 1
        validPick = false;
        while ~validPick
            sticksToPick = input('Enter sticks number (1~3): ');
            if sticksToPick >= 1 && sticksToPick <= maxPick && sticksToPick <= totalSticks
                validPick = true;
            else
                fprintf('Error! Enter the correct number.\n');
            end
        end
    else  % 컴퓨터의 차례일 경우, 난수 생성
        sticksToPick = randi([1, min(maxPick, totalSticks)]);
        fprintf('Computer gets %d sticks.\n', sticksToPick);
    end

    % 막대 개수 업데이트
    totalSticks = totalSticks - sticksToPick;

    % 승자 결정
    if totalSticks <= 0
        if currentPlayer == 1
            winner = players(2);
        else
            winner = players(1);
        end
        fprintf('\n%s wins!\n', winner);
    end

    % 플레이어 변경
    currentPlayer = mod(currentPlayer, 2) + 1;
end
