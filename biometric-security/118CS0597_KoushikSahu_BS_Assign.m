clc; % clear screen
close all; % clear memory
format compact; % compact o/p

% parameters
mu_g = 0;
sigma_g = 1;
mu_i = 0.4;
sigma_i = 0.6;
sample_cnt = 1e5;

% gaussian distributions
x = linspace(-10, 10, sample_cnt);
y_g = normpdf(x, mu_g, sigma_g);
y_i = normpdf(x, mu_i, sigma_i);

% plotting
% subplot(2, 1, 1);
% plot(x, y_g, ':', x, y_i, '-.')
% legend('Mean: 0 Variance: 1', 'Mean: 0.4 Variance: 0.6')

% discrimination index
d = sqrt(2)*(mu_g-mu_i) / (sigma_g.^2 + sigma_i.^2);
s = sprintf('Discrimination index: %f', d);
disp(s)

% roc curve
c_g = normcdf(x, mu_g, sigma_g);
c_i = normcdf(x, mu_i, sigma_i);
x_roc = 1-c_g;
y_roc = 1-c_i;
% subplot(2, 1, 2);
% plot(x_roc, y_roc);

% deviating mean and variance and considering roc
mu_g = linspace(0, 0.75, 5);
sigma_g = linspace(0, 0.75, 5);
mu_i = linspace(0.25, 1, 5);
sigma_i = linspace(0.25, 1, 5);

for i=1:5
    c_g = normcdf(x, mu_g(i), sigma_g(i));
    c_i = normcdf(x, mu_i(i), sigma_i(i));
    x_roc = 1-c_g;
    y_roc = 1-c_i;
    plot(x_roc, y_roc, 'DisplayName', "Mean: "+mu_g(i)+" "+mu_i(i)+" Variance: "+sigma_g(i)+" "+ sigma_i(i))
    hold on;
    d = sqrt(2)*(mu_g(i)-mu_i(i)) / (sigma_g(i).^2 + sigma_i(i).^2);
    s = sprintf('Discrimination index: %f', d);
    disp(s)
end

legend show

