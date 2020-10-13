
// 数学基础

1. 离散点求导的数学理论与方法
https://blog.csdn.net/gophae/article/details/102518309


2. 非线性回归的数学理论与方法(非线性最小二乘法)
https://blog.csdn.net/gophae/article/details/102518428


3. 三阶样条曲线
 https://blog.csdn.net/gophae/article/details/102808083
<< numerical methods for engineers >>

// 笔记
https://kluge.in-chemnitz.de/opensource/spline/


4.  BFS， DFS， A*
// DFS总是向最深的方向搜索
// BFS使用queue,先进的先出
// DFS用到了栈结构，先进后出
// 这里可以看到，广度优先搜索会 比深度优先搜索范围更大，虽然可以绝对保证最优性结果，但是效率远不及深度优先，而深度优先的问题则在于无法保证最优


5. 自动驾驶中的滞后碰撞检测(lazy-collision-checking)
https://blog.csdn.net/gophae/article/details/103785393

<< Fast Collision Checking for Intelligent Vehicle Motion Planning >>
<< Dynamic Motion Planning Framework for Autonomous Driving in Urban Environments >>


6. Matlab解析LQR与MPC的关系
https://blog.csdn.net/gophae/article/details/104546805



7. 离散点曲率拟合
https://blog.csdn.net/gophae/article/details/104296957



8. LQR轨迹跟踪算法Python/Matlab算法实现_LQRmatrix推导
https://blog.csdn.net/gophae/article/details/104538585


9. Matlab解析LQR与MPC的关系
https://blog.csdn.net/gophae/article/details/104546805


// 笔记
10. PID参数整定法
https://blog.csdn.net/gophae/article/details/104554398



11.
对于原始轨迹的噪声过滤方法和曲率计算方法
对于地图采样获得的轨迹，通过cross entropy的方式，进行噪声过滤。曲率计算采用三点式计算圆半径获得
https://blog.csdn.net/gophae/article/details/104661890





// 凸优化
<< Practical optimization algorithms and engineering applications >>




// 车辆控制

1.
自动驾驶车辆转向控制(通过扭矩控制实现方向盘转角控制)
通过增量式PID控制器实现通过对自动驾驶车辆的EPS进行扭矩响应控制从而实现对期望方向盘转角的控制
https://blog.csdn.net/gophae/article/details/100777514

自动驾驶车辆转向控制（通过支持转角控制的EPS实现角速度控制）
https://blog.csdn.net/gophae/article/details/101977212?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param




2.
动态调节PID参数
// 我们发现其实PID实现确实不难，但是三个系数的选择却很难，那么如何选择PID系数呢？我们可以在我们的控制循环中通过一定的算法不断尝试，下面我提供给大家一种寻找参数的算法
https://blog.csdn.net/AdamShan/article/details/78458325

https://blog.csdn.net/gophae/article/details/102468916


3.  如何实现简单的循迹行驶
https://blog.csdn.net/gophae/article/details/102469489


4. // 自动驾驶横向运动学分析和非线性问题处理方法
https://blog.csdn.net/gophae/article/details/102499064







6. LQR轨迹跟踪算法Python/Matlab算法实现_LQRmatrix推导
// https://blog.csdn.net/gophae/article/details/103458473
// 
https://blog.csdn.net/gophae/article/details/103199757#comments

7. Pure Pursuit trajectory tracking and Stanley trajectory tracking总结与比较

https://blog.csdn.net/gophae/article/details/100012763





python实现梯度下降法
https://blog.csdn.net/gophae/article/details/104209396
// python实现牛顿法(newton's method)
https://blog.csdn.net/gophae/article/details/104210974



// 代码
5. Bezier(贝塞尔)曲线
Bezier(贝塞尔)曲线的轨迹规划在自动驾驶中的应用
https://blog.csdn.net/gophae/article/details/102514727
https://blog.csdn.net/gophae/article/details/102518206

自动驾驶使用贝塞尔曲线进行动态障碍物避障测试
https://blog.csdn.net/gophae/article/details/103661496

自动驾驶实测：贝塞尔曲线静态障碍物避障
https://blog.csdn.net/gophae/article/details/103161505

matlab代码
https://blog.csdn.net/gophae/category_9399390.html