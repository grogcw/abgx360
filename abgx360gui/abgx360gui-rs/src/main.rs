slint::include_modules!();
use slint::SharedString;

fn main() -> Result<(), slint::PlatformError> {
    let app = AppWindow::new()?;

    let weak_browse = app.as_weak();
    app.on_browse(move || {
        if let Some(path) = rfd::FileDialog::new().pick_file() {
            if let Some(app) = weak_browse.upgrade() {
                app.set_input_path(SharedString::from(path.display().to_string()));
            }
        }
    });

    let weak_run = app.as_weak();
    app.on_run(move || {
        if let Some(app) = weak_run.upgrade() {
            let input = app.get_input_path();
            println!("Run abgx360 with {}", input);
        }
    });

    app.run()
}
