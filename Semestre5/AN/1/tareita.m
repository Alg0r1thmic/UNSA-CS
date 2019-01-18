function tareita()
f1 = @(x) x.^2+2*x-1;
f2 = @(x) cos(x+pi);
f3 = @(x) 1./(1+x.^2);
x = linspace(-10,10,21);
y = f1(x);
z = f2(x);
w = f3(x);
plot(x,y,'r');
hold on
plot(x,z,'g');
hold on
plot(x,w,'y');
grid on
endfunction