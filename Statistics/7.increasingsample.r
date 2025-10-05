 # Parameters
 mu <- 5
 sigma <- 2
 sample_sizes <- c(10, 30, 100, 500, 1000)
 N_sim <- 1000
 # Initialize vectors
 means <- numeric(length(sample_sizes))
 vars <- numeric(length(sample_sizes))
 # Simulation
 set.seed(123)
 for (i in 1:length(sample_sizes)) {
 n <- sample_sizes[i]
 sample_means <- replicate(N_sim, mean(rnorm(n, mean = mu, sd = sigma)))
 means[i] <- mean(sample_means)
 vars[i] <- var(sample_means)
 }
 # Graphical Output
 par(mfrow = c(1, 2))
 # Plot sample means
 plot(sample_sizes, means, type = "b", col = "blue", main = "Convergence of Sample Mean", xlab = "Sample Size", ylab = "Sample Mean")
 abline(h = mu, col = "red", lwd = 2)
 # Plot sample variances
 plot(sample_sizes, vars, type = "b", col = "green", main = "Convergence of Sample Variance", xlab = "Sample Size", ylab = "Sample Variance")
 abline(h = sigma^2, col = "red", lwd = 2)