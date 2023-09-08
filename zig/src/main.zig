const std = @import("std");
const new = @import("new.zig");  


pub  fn main() void {

    var generator = new.Generator(u8).init(10);
    for (generator.next()) |i| {
        std.debug.print("{}", .{i});
    }
   
}