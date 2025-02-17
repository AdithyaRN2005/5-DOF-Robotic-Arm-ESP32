clc
clear
clear all

th1 = 0;

%these are the origin, orientiation of gripper
phi = 0 *pi/180;%angle of final link with ground
l1 = 0.15;
l2 = 0.07;
l3 = 0.186;
xc =0;
zc = 0;
yc = 0;


%these are the end coordinatess
th = 0:0.01 :0.1;
 x = 0 + 0*sin(th);
 y = 0.28+ 0*cos(th);
 z = 0.09 + th;
 

for i=1:length(th)
    s = sqrt(x(i)^2 + y(i)^2);
    y2= z(i) - l3*sin(phi);
    x2= s - l3*cos(phi);
    th1 = pi/2 + atan2(-y(i),x(i))

%this equaition is for calculating the angles 
     th2= acos( (x2^2+y2^2+l1^2-l2^2)/2/l1/sqrt(x2^2+y2^2)) + atan2(y2,x2);
     
    th3= atan2 ( y2-l1*sin(th2),x2-l1*cos(th2));

    ang1(i)= th1*180/pi
    ang2(i)= th2*180/pi
    ang3(i)= 90 + (th3- th2)*180/pi
    ang4(i) = (90+ phi*180/pi - th2*180/pi - (th3- th2)*180/pi)*60/90

%this is just the calculatin of the position of joints
        v1=[0 ;  yc+l1*cos(th2) ; zc +  l1*sin(th2)];
        v2=v1+[0; l2*cos(th3);l2*sin(th3)];
        v3 = v2 + [ 0; l3*cos(phi); l3*sin(phi)];
      
        

        %this is the rotation matrix for m1 angle(base motor)
        T = [cos(th1) , sin(th1), 0;
     -sin(th1),cos(th1) , 0;
            0, 0 ,1 ];


%we give the m1 angle to rotate it around.
       v3 = T*v3;
        v2 = T*v2;
        v1 = T*v1;
        
    %then we plot it.
        axis equal;
        grid on;
        
        cla

        plot3([xc v1(1)],[yc v1(2)],[zc v1(3)], "-or",'LineWidth',2);
        plot3([v1(1) v2(1)],[v1(2) v2(2)],[v1(3) v2(3)],"-ob",'LineWidth',2);
        plot3([v2(1) v3(1)],[v2(2) v3(2)],[v2(3) v3(3)],"-og",'LineWidth',2);
        str = sprintf('θ1: %.2f°\nθ2: %.2f°\nθ3: %.2f°\nθ4: %.2f°', ang1(i), ang2(i), ang3(i), ang4(i));
text(-0.25, 0.25, 0.25, str, 'FontSize', 10, 'BackgroundColor', 'white');
        % Joint Labels - Positioned slightly offset from each joint

        xlim([-0.3 0.3]);
        ylim([-0.3 0.3]);
        zlim([0 0.3]);
        hold on
        pause (0.2);
        
end
text(0 + 0.02, 0 + 0.02, 0, 'Joint 1', 'FontSize', 10, 'Color', 'yellow');
text(0 - 0.05, 0 + 0.02, 0, 'Joint 2', 'FontSize', 10, 'Color', 'cyan');
text(v1(1) + 0.02, v1(2) + 0.02, v1(3), 'Joint 3', 'FontSize', 10, 'Color', 'red');
text(v2(1) + 0.02, v2(2) + 0.02, v2(3), 'Joint 4', 'FontSize', 10, 'Color', 'blue');
text(v3(1) - 0.05, v3(2) + 0.02, v3(3), 'Joint 5', 'FontSize', 10, 'Color', 'green');
text(v3(1) + 0.02, v3(2) + 0.02, v3(3), 'End Effector', 'FontSize', 10, 'Color', 'magenta');
text(v3(1) + 0.02, v3(2) + 0.04, v3(3)+0.02, 'End point=(0, 0.28, 1.9)', 'FontSize', 10, 'Color', 'black');