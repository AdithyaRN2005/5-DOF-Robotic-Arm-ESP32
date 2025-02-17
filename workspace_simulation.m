clc
clear all
th0 = 0:0.1*pi:2*pi;
th1 = 0:0.25*pi:pi;
th2 = 0:0.25*pi:2*pi;
phi = 0;
l1 = 0.15;
l2 = 0.07;
l3 = 0.186;
xc =0;
zc = 0;
yc = 0;

T = zeros(3, 3, length(th0));
for m = 1:length(th0)
  
     T(:,:,m) = [cos(th0(m)) , -sin(th0(m)), 0;
                  sin(th0(m)),cos(th0(m)) , 0;
                       0, 0 ,1 ];
end

for m = 1 :length(th0)
    for i = 1:length(th1)
        for j= 1: length(th2)
            
    
    
           v1=[0 ;  yc+l1*cos(th1(i)) ; zc +  l1*sin(th1(i))]
        v2=v1+[0; l2*cos(th2(j));l2*sin(th2(j))];
        v3 = v2 + [ 0; l3*cos(phi); l3*sin(phi)];
        axis equal;
        grid on;
        v3 = T(:, : ,m)*v3;
        v2 = T(:, : ,m)*v2;
        v1 = T(:, : ,m)*v1;
         xlim([-0.5 0.5]);
        ylim([-0.5 0.5]);
        zlim([-0.5 0.5]);
        plot3([0 0],[0 0],[0 zc],'y' );
        scatter3(v3(1), v3(2), v3(3)); hold on;
        %plot3([xc v1(1)],[yc v1(2)],[zc v1(3)],'r');
        % plot3([v1(1) v2(1)],[v1(2) v2(2)],[v1(3) v2(3)],'b')
        % plot3([v2(1) v3(1)],[v2(2) v3(2)],[v2(3) v3(3)],'g')      
    
        end
    end
end
