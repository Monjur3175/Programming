 # Parameters
 mu0 <- 5  # Null hypothesis mean
 mu1 <- 6  # True population mean
 sigma <- 2  # Population standard deviation
 n <- 30  # Sample size
 alpha <- 0.05  # Significance level
 # Generate sample data
 set.seed(123)
 sample_data <- rnorm(n, mean = mu1, sd = sigma)
 # Step 1: State hypotheses
 print("H0: mu = 5")
 print("H1: mu > 5")
 # Step 2: Choose significance level
 print(paste("Significance level (alpha):", alpha))
 # Step 3: Calculate test statistic
 t_stat <- (mean(sample_data) - mu0) / (sd(sample_data) / sqrt(n))
 print(paste("Test Statistic (t):", t_stat))
 # Step 4: Determine critical value or p-value
 critical_value <- qt(1 - alpha, df = n-1)
 p_value <- pt(t_stat, df = n-1, lower.tail = FALSE)
 print(paste("Critical Value:", critical_value))
 print(paste("P-value:", p_value))
 # Step 5: Make a decision
 if (t_stat > critical_value) {
 decision <- "Reject H0"
 } else {
 decision <- "Fail to reject H0"
 }
 print(paste("Decision:", decision))
 # Graphical Output
 par(mfrow = c(1, 2))
 # Histogram with critical region
 hist(sample_data, breaks = 30, col = "lightblue", main = "Sample Data", xlab = "Value", border = "white")
 abline(v = mu0, col = "red", lwd = 2)
 abline(v = mean(sample_data), col = "blue", lwd = 2)
# Density plot with critical region
 plot(density(sample_data), col = "blue", lwd = 2, main = "Density Plot", xlab = "Value")
 abline(v = critical_value, col = "red", lty = 2)