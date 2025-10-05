# Set parameters
n <- 10
N_sim <- 1000
set.seed(120)

# Generate data from t-distribution with n-1 degrees of freedom
t_data <- rt(N_sim, df = n-1)

# Generate data from standard normal distribution
normal_data <- rnorm(N_sim)

# Set plotting layout (2 rows, 2 columns for 4 plots)
par(mfrow = c(2, 2))

# Plot 1: Histogram of t-distribution data
hist(t_data, breaks = 30, col = "lightblue", probability = TRUE, 
     main = "t-Distribution Data", xlab = "Value", border = "white")
curve(dt(x, df = n-1), add = TRUE, col = "red", lwd = 2)

# Plot 2: Histogram of normal distribution data
hist(normal_data, breaks = 30, col = "lightgreen", probability = TRUE, 
     main = "Normal Distribution Data", xlab = "Value", border = "white")
curve(dnorm(x), add = TRUE, col = "blue", lwd = 2)

# Plot 3: Density comparison
plot(density(t_data), col = "red", lwd = 2, 
     main = "Density Comparison", xlab = "Value", ylab = "Density",
     ylim = c(0, max(c(density(t_data)$y, density(normal_data)$y))))
lines(density(normal_data), col = "blue", lwd = 2)
legend("topright", legend = c("t-Distribution", "Normal Distribution"), 
       col = c("red", "blue"), lwd = 2)

# Plot 4: Q-Q plot for t-distribution
qqplot(rt(N_sim, df = n-1), t_data, 
       main = "Q-Q Plot: t-Distribution",
       col = "red", 
       xlab = "Theoretical Quantiles", 
       ylab = "Sample Quantiles")
abline(0, 1, col = "black", lwd = 1) # Add reference line

# Reset plotting layout
par(mfrow = c(1, 1))